while (true) {  
    market_data = exchange.get_stream();  
    inference_engine.run(market_data, &prediction);  
    if (prediction > threshold) execute_order();  
    std::this_thread::sleep_for(1us);  // 1M inferences/sec  
  }  