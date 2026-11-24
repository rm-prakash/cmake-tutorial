#!/usr/bin/env python3
"""Package installed files and create checksums. Demonstrative; no signing."""
from pathlib import Path
import argparse,hashlib,json,tarfile,os
p=argparse.ArgumentParser()
for name in ('stage','out','target','config'): p.add_argument(name)
a=p.parse_args()
root=Path(a.stage).resolve(); dest=Path(a.out).resolve()
if not root.is_dir(): p.error('No installed stage directory')
files=sorted(f for f in root.rglob('*') if f.is_file())
if not files: p.error('Stage is empty')
dest.mkdir(parents=True,exist_ok=True)
base=f'embeddedcore-2.0.0-{a.target}-{a.config.lower()}'
records=[{'path':f.relative_to(root).as_posix(),'size':f.stat().st_size,'sha256':hashlib.sha256(f.read_bytes()).hexdigest()} for f in files]
manifest={'project':'EmbeddedCore','version':'2.0.0','target':a.target,'configuration':a.config,'files':records,'qualification':'Educational example; no cryptographic validation or release provenance claims'}
(dest/f'{base}.json').write_text(json.dumps(manifest,indent=2)+'\n')
archive=dest/f'{base}.tar.gz'
with tarfile.open(archive,'w:gz') as tar:
  for f in files: tar.add(f,arcname=f'{base}/{f.relative_to(root).as_posix()}')
digest=hashlib.sha256(archive.read_bytes()).hexdigest()
(dest/f'{base}.sha256').write_text(f'{digest}  {archive.name}\n')
print('Packaged',archive,'SHA256',digest)
