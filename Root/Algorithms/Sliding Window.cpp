void sliding_window_minimum(std::vector<int> & ARR, int K) {
  // pair<int, int> represents the pair (ARR[i], i)
  std::deque< std::pair<int, int> > window;
  for (int i = 0; i < ARR.size(); i++) {
     while (!window.empty() && window.back().first >= ARR[i])
       window.pop_back();
     window.push_back(std::make_pair(ARR[i], i));

     while(window.front().second <= i - K)
       window.pop_front();

     std::cout << (window.front().first) << ' ';
  }
}
