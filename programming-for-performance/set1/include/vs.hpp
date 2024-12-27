/**
 * You can use this file for programmign task 1 of set 1.
 */

#pragma once

namespace pfp {

template <class dtype>
class vs {
   private:
    std::unordered_set<dtype, int> tree;

   public:
    void insert(dtype val) {
        tree.insert(val);
    }

    int count(dtype val) {
        return tree.count(val);
    }
};

}  // namespace pfp
