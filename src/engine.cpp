#include <onnxruntime_cxx_api.h>  

void run_inference(ORT_API* api, float* input, float* output) {  
  Ort::Session session = /* ... */;  
  Ort::IoBinding binding(session);  

  // Zero-copy I/O for microsecond latency  
  binding.BindInput("input", Ort::Value::CreateTensor<float>(  
    api, input, input_shape, input_dims  
  ));  
  binding.BindOutput("output", Ort::Value::CreateTensor<float>(  
    api, output, output_shape, output_dims  
  ));  

  session.Run(Ort::RunOptions{}, binding);  // No allocations!  
}  