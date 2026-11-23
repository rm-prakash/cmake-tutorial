# include() executes in the caller's variable scope.
set(INCLUDED_NOTE "set inside included module")

function(demonstrate_function_scope)
    set(SCOPE_MESSAGE "changed inside function")
    message(STATUS "Function sees: ${SCOPE_MESSAGE}")
endfunction()

function(publish_to_caller out_variable)
    set(${out_variable} "published using PARENT_SCOPE" PARENT_SCOPE)
endfunction()
