#!/usr/bin/env python3
import hashlib,json,sys,tarfile
from pathlib import Path
if len(sys.argv)!=4: raise SystemExit('Usage: verify-package.py archive manifest checksum')
archive,mp,side=map(Path,sys.argv[1:]); manifest=json.loads(mp.read_text())
assert hashlib.sha256(archive.read_bytes()).hexdigest()==side.read_text().split()[0], 'Archive checksum mismatch'
with tarfile.open(archive,'r:gz') as tar:
  members={Path(m.name).relative_to(Path(m.name).parts[0]).as_posix():m for m in tar.getmembers() if m.isfile()}
  assert set(members)=={r['path'] for r in manifest['files']},'Manifest file list mismatch'
  for record in manifest['files']:
    raw=tar.extractfile(members[record['path']]).read()
    assert len(raw)==record['size'] and hashlib.sha256(raw).hexdigest()==record['sha256'],record['path']
print('PASS: archive, checksum and manifest match')
