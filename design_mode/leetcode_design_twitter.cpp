// practice make perfect :)
// Author: Duan Lian

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class Twitter {
 public:
  // Write your code there...
  struct Node {
    unordered_set<int> followee;
    list<int> tweet;
  };

  int recent_count_, timer_;
  unordered_map<int, int> tweet_time_;
  unordered_map<int, Node> user_;

  Twitter() {
    recent_count_ = 10;
    timer_ = 0;
  }

  void postTweet(int userId, int tweetId) {
    if (user_.find(userId) == user_.end()) {
      user_[userId] = Node();
    }
    tweet_time_[tweetId] = ++timer_;
    user_[userId].tweet.push_front(tweetId);
  }

  vector<int> getNewsFeed(int userId) {
      vector<int> res;
      list<int> recent_list;
      for (const auto &it : user_[userId].tweet) {
        recent_list.emplace_back(it);
      }

      for (auto &it : user_[userId].followee) {
        // user might follow itself
        if (it == userId) continue;

        list<int> temp_list;
        auto i = recent_list.begin(), j = user_[it].tweet.begin();
        while (i != recent_list.end() && j != user_[it].tweet.end()) {
          if (tweet_time_[*i] < tweet_time_[*j]) {
            temp_list.push_back(*j);
            j++;
          } else {
            temp_list.push_back(*i);
            i++;
          }
        }
        for (; i != recent_list.end(); i++) temp_list.push_back(*i);
        for (; j != user_[it].tweet.end(); j++) temp_list.push_back(*j);
        recent_list.assign(temp_list.begin(), temp_list.end());
      }
      for (const auto &it : recent_list) {
        res.push_back(it);
        if (res.size() >= recent_count_) break;
      }
      return res;
  }

  void follow(int followerId, int followeeId) {
      if (user_.find(followerId) == user_.end()) {
        user_[followerId] = Node();
      }
      if (user_.find(followeeId) == user_.end()) {
        user_[followeeId] = Node();
      }
      user_[followerId].followee.insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    user_[followerId].followee.erase(followeeId);
  }
};



