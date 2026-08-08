/*  pbds万能头
<bits/extc++.h>
牛客、codeforces、atcoder、洛谷、HDU、BZOJ、vijos、loj都是支持的，POJ不支持
*/
// #include<bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/*  模板形参
Key: 储存的元素类型，如果想要存储多个相同的 Key 元素，则需要使用类似于 std::pair 和 struct 的方法，并配合使用
  lower_bound 和 upper_bound 成员函数进行查找
Mapped: 映射规则（Mapped-Policy）类型，如果要指示关联容器是 集合，类似于存储元素在 std::set 中，此处填入 null_type，
  低版本 g++ 此处为 null_mapped_type；如果要指示关联容器是 带值的集合，类似于存储元素在 std::map 中，此处填入类似于 std::map<Key, Value> 的 Value 类型
Cmp_Fn: 关键字比较函子，例如 std::less<Key>
Tag: 选择使用何种底层数据结构类型，默认是 rb_tree_tag．__gnu_pbds 提供不同的三种平衡树，分别是：
rb_tree_tag：红黑树，一般使用这个，后两者的性能一般不如红黑树
splay_tree_tag：splay 树
ov_tree_tag：有序向量树，只是一个由 vector 实现的有序结构，类似于排序的 vector 来实现平衡树，性能取决于数据想不想卡你
Node_Update：用于更新节点的策略，默认使用 null_node_update，若要使用 order_of_key 和 find_by_order 方法，需要使用
  tree_order_statistics_node_update
Allocator：空间分配器类型
*/

// 键不可重复的平衡树（红黑树）
template<typename T>
using BT = __gnu_pbds::tree<
  T,
  __gnu_pbds::null_type,
  std::less<T>,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update
>;

// 键可重复的平衡树（红黑树），通过 pair<T, int> 使键唯一
template<typename T>
using MBT = __gnu_pbds::tree<
  std::pair<T, int>,
  __gnu_pbds::null_type,
  std::less<std::pair<T, int>>,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update
>;
static int timer = 0;
// 插入：tr.insert({x, ++timer});

/*  成员函数
insert(x)：向树中插入一个元素 x，返回 std::pair<point_iterator, bool>，其中第一个元素代表插入位置的迭代器，第二个
  元素代表是否插入成功．
erase(x)：从树中删除一个元素/迭代器 x．如果 x 是迭代器，则返回指向 x 下一个的迭代器（如果 x 是 end() 则返回 end()）；
  如果 x 是 Key，则返回是否删除成功（如果不存在则删除失败）．
order_of_key(x)：返回严格小于 x 的元素个数（以 第二个参数Cmp_Fn作为比较逻辑）．
find_by_order(x)：返回第二个参数Cmp_Fn比较的排名所对应元素的迭代器．相当于kth(x)，x为0-based
lower_bound(x)：返回第一个不小于 x 的元素所对应的迭代器（以 Cmp_Fn 作为比较逻辑）．
upper_bound(x)：返回第一个严格大于 x 的元素所对应的迭代器（以 Cmp_Fn 作为比较逻辑）．
join(x)：将 x 树并入当前树，x 树被清空（必须确保两树的 比较函数 和 元素类型 相同）．
split(x,b)：以 Cmp_Fn 比较，小于等于 x 的属于当前树，其余的属于 b 树．
empty()：返回是否为空．
size()：返回大小．
*/