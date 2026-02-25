class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tmpMap;
        for(int i = 0; i < nums.size(); i++)
        {
            if(tmpMap.count(target - nums[i]))
            {
                return {tmpMap[target - nums[i]], i};
            }
            else
            {
                tmpMap[nums[i]] = i;
            }
        }
        return {};
    }
};

//暴力能做出来，但太耗费时间

/*unorderd_map常用方法
unordered_map 提供了多种常用的成员函数，下面是一些常用的方法：
1. insert
插入一个元素（键值对）到 unordered_map 中。如果键已经存在，则不会覆盖原有的值。
unordered_map&lt;Key, Value&gt;::iterator insert(const std::pair&lt;Key, Value&gt;&amp; value);
unordered_map&lt;Key, Value&gt;::iterator insert(Key&amp;&amp; key, Value&amp;&amp; value);


1.返回值：返回一个迭代器，指向新插入的元素或者已经存在的元素。

示例：
std::unordered_map&lt;int, std::string&gt; myMap;
myMap.insert({1, "apple"});
myMap.insert({2, "banana"});

2. find
查找指定的键并返回指向该元素的迭代器。如果键不存在，则返回 end()。
unordered_map&lt;Key, Value&gt;::iterator find(const Key&amp; key);
unordered_map&lt;Key, Value&gt;::const_iterator find(const Key&amp; key) const;


2.返回值：返回一个迭代器，指向找到的元素；如果没有找到，则返回 end()。

示例：
auto it = myMap.find(2);
if (it != myMap.end()) {
    std::cout &lt;&lt; "Found: " &lt;&lt; it-&gt;second &lt;&lt; std::endl;
} else {
    std::cout &lt;&lt; "Not found!" &lt;&lt; std::endl;
}

3. erase
删除指定键的元素。
size_t erase(const Key&amp; key);
void erase(unordered_map&lt;Key, Value&gt;::iterator pos);
void erase(unordered_map&lt;Key, Value&gt;::iterator first, unordered_map&lt;Key, Value&gt;::iterator last);


3.返回值：对于 erase(const Key&amp;)，返回删除的元素个数（通常为 0 或 1）；对于其他重载，返回删除的元素个数（例如迭代器范围删除）。

示例：
myMap.erase(1);  // 删除键为 1 的元素

4. size
返回容器中元素的数量。
size_t size() const;


4.返回值：容器中的元素数量。

示例：
std::cout &lt;&lt; "Size: " &lt;&lt; myMap.size() &lt;&lt; std::endl;

5. empty
检查 unordered_map 是否为空。
bool empty() const;


5.返回值：如果容器为空，返回 true，否则返回 false。

示例：
if (myMap.empty()) {
    std::cout &lt;&lt; "The map is empty!" &lt;&lt; std::endl;
}

6. clear
清空所有元素。
void clear();


6.返回值：无。

示例：
myMap.clear();  // 清空所有元素

7. operator[]
通过键访问元素。如果键不存在，则插入一个默认值的元素。
Value&amp; operator[](const Key&amp; key);
Value&amp; operator[](Key&amp;&amp; key);


7.返回值：返回键对应的值的引用。如果键不存在，会自动插入该键并给其赋一个默认值。

示例：
myMap[4] = "orange";  // 插入或修改键 4 对应的值
std::cout &lt;&lt; myMap[4] &lt;&lt; std::endl;  // 输出 "orange"

8. at
通过键访问元素。如果键不存在，会抛出 out_of_range 异常。
Value&amp; at(const Key&amp; key);
const Value&amp; at(const Key&amp; key) const;


8.返回值：返回键对应的值的引用。
9.异常：如果键不存在，会抛出 std::out_of_range 异常。

示例：
try {
    std::cout &lt;&lt; myMap.at(3) &lt;&lt; std::endl;
} catch (const std::out_of_range&amp; e) {
    std::cout &lt;&lt; "Key not found!" &lt;&lt; std::endl;
}

9. begin 和 end
返回容器的迭代器，分别指向容器的第一个元素和最后一个元素后的位置。
unordered_map&lt;Key, Value&gt;::iterator begin();
unordered_map&lt;Key, Value&gt;::iterator end();
unordered_map&lt;Key, Value&gt;::const_iterator begin() const;
unordered_map&lt;Key, Value&gt;::const_iterator end() const;


10.返回值：返回指向容器第一个元素的迭代器和指向容器末尾元素后位置的迭代器。

示例：
for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    std::cout &lt;&lt; it-&gt;first &lt;&lt; ": " &lt;&lt; it-&gt;second &lt;&lt; std::endl;
}

10. bucket_count 和 bucket_size
这两个函数与容器的底层哈希结构有关：

11.bucket_count 返回容器中桶的数量。
12.bucket_size 返回某个桶中元素的数量。

size_t bucket_count() const;
size_t bucket_size(size_t n) const;

示例：
std::cout &lt;&lt; "Number of buckets: " &lt;&lt; myMap.bucket_count() &lt;&lt; std::endl;

11. rehash
重新哈希容器，将桶的数量增加到指定的数量。
void rehash(size_t count);


13.参数：count 指定要增加的桶数。
示例：
myMap.rehash(20);  // 将桶数量重新调整为 20
*/