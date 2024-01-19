# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer[]}
def max_sliding_window(nums, k)
    d, s = [], 0
    out = []
    nums.each_index{ |i|
        d.pop while d[s] && nums[d[-1]] < nums[i]
        d << i
        s += 1 if d[s] == i - k
        out << nums[d[s]] if i >= k - 1
    }
    out
end