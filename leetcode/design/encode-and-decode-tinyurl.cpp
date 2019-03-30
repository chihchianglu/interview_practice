//
// Created by Lu, Chih-chiang on 2019-02-06.
//

/**
 * Encode and Decode TinyURL
 *
 * TinyURL is a URL shortening service where you enter a URL
 * such as https://leetcode.com/problems/design-tinyurl and
 * it returns a short URL such as http://tinyurl.com/4e9iAk.
 *
 * Design the encode and decode methods for the TinyURL service.
 * There is no restriction on how your encode/decode algorithm should work.
 *
 * You just need to ensure that a URL can be encoded to a tiny URL and
 * the tiny URL can be decoded to the original URL.
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  // Encodes a URL to a shortened URL.
  std::string encode(std::string longUrl) {
    urls_.push_back(longUrl);
    return "http://tinyurl.com/" + std::to_string(urls_.size() - 1);
  }

  // Decodes a shortened URL to its original URL.
  std::string decode(std::string shortUrl) {
    auto pos = shortUrl.find_last_of("/");
    return urls_[std::stoi(shortUrl.substr(pos + 1))];
  }

 private:
  std::vector<std::string> urls_;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(int argc, char *argv[]) {
  Solution solution;
  if (solution.decode(solution.encode("https://leetcode.com/problems/design-tinyurl"))
      != "https://leetcode.com/problems/design-tinyurl") {
    throw std::runtime_error("error");
  }
  return 0;
}
