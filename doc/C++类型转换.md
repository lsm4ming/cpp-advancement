### static_cast

````
static_cast 是一种编译时类型转换，不执行运行时类型检查，没有额外的性能开销。
static_cast 支持基本类型转换之间的转换，也支持指针和引用类型转换和枚举类型转换。
````

```cpp
static_cast<T>(expr)

// 使用示例
int a = static_cast<int>(3.14);
``

static_cast 


### dynamic_cast

````
dynamic_cast 的作用和 static_cast 类似，但是它是发生在运行时，会执行运行时类型检查。
dynamic_cast 依赖 RTTI 进行运行时检查，因此需要在类中至少有一个虚函数。
````

```cpp
dynamic_cast<T>(expr)

// 使用示例
int a = dynamic_cast<int>(3.14);
```

### reinterpret_cast

````
reinterpret_cast的作用是将指针或者引用的类型转换为其它任意类型。
````

```cpp
reinterpret_cast<T>(expr)

// 使用示例
char *p = new char;
double *q = reinterpret_cast<double*>(p);
int c = reinterpret_cast<int>(p);  // 报错，因为指针有可能比int占用更多的内存
u_int64_t d = reinterpret_cast<u_int64_t>(p);
```


### const_cast

````
const_cast的作用是将指针或者引用的const属性去掉，但是不能修改其指向的对象。
需要谨慎使用
````

```cpp
const_cast<T>(expr)

// 使用示例
const int *p = new int(1);
int *q = const_cast<int *>(p);
```


### 四种转换类型对比

转换类型     | 名称   |   转换时机 |   是否类型检查 | 
-------- | -----   |  -----        | -----       |
static_cast  | 静态类型转换 |  编译时 |  否 |  
dynamic_cast  | 动态类型转换|  运行时 | 是|
const_cast  | const转换|   编译时 |  否|
reinterpret_cast  | 重新解释转换| 编译时 |  否|