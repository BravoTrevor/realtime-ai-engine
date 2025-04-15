add_executable(wasm_ai engine.cpp simd_math.cpp)  
target_compile_options(wasm_ai PRIVATE "-msimd128")  # WASM SIMD  
set_target_properties(wasm_ai PROPERTIES SUFFIX ".js")  