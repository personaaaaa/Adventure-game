Adventure Game
--
Adventure Game - practice for c language learning.

### 小王的探险故事 <br >

    小王是一个喜欢探险的好孩子，有一次他和几个好朋友去洞穴挖宝石，挖到的宝石大家一起平分。
    可是洞穴里面总是会发生一些难以预料的灾难事件（洪水、地震、塌方...），要是不幸遇到这些
    倒霉事，不仅挖到的财宝会全部丢失，小王也会有生命危险:(
    
    但危险越大也就意味着挖到的宝藏越多，只要小王能赶在灾难发生之前离开洞穴，他就可以拿走所有
    的财宝。但小王可是一个很谨慎的人，他怎么可能会冒着生命危险去做这种事情呢？原来传闻说：只有
    当冒险者第二次遇到同一种灾难的时候，才会丢失财宝、被困在洞穴里面。
    
    如果传闻是真的，小王就只要遇到第一次灾难发生时携款逃走不就好了吗？（虽然代价是遭到好朋友
    的鄙视:(。
    
    接下来，请小李设计一个算法程序，让小王保证能安全回来的同时，尽可能多的带走财宝。
计划
---
- [ ] 对象数据用结构体保存
    - [ ] Gem 写入结构体，并用单独头文件保存
    - [ ] Disaster 写入结构体，并用单独头文件保存
    
C ++ 语法
---

#### 变量（variable）
- 变量是用来做什么的
    
    TODO
    
- 什么是变量

    TODO

#### 常量（constant）

TODO

#### 类型（type）
- 基本类型（basic type）
  ```
  // 不可被拆分成其他类型的类型，例如 char, int, long, float, double, 指针类型
  int a = 0;
  char b = 'c';
  long c = 1000;
  float d = 4.5;
  float e = 4.5f;
  double f = 3.6;
  // 各种各样的指针类型
  float* a;
  double* b;
  long* c;
  ```
- 复杂类型（complex type）
 
  由基本类型、复杂类型组合在一起的类型。组合方式有两种：1、结构体（struct）；2、类（class）
  
  ```
  // 1. 基本类型组合在一起(每个基本类型可以被称之为这个复杂类型的属性)
  struct Person {
      // 年龄
      int age;
      // 名字
      char *name;
      // 身高
      float height;
      // 体重
      float weight;
  };
  // 创建一个变量，类型是 Person
  struct Person son = {3, "wang", 1.67, 65}; // 花括号里面的数据，按照顺序依次初始化 son 里面的属性
  struct Person mother; // 这里没有使用花括号去初始化 mother 里面的属性，因此属性的值是不确定的。
  
  
  ```
 
  ```
  // 2. 复杂类型组合成复杂类型（这里采用结构体 struct ）
  struct Famliy {
      // Person 也是一个复杂类型
      struct Person son;
      struct Person mother;
      struct Person father;
  };
  
  // 创建一个变量，类型是 Famliy。并分别初始化 Famliy 里面的属性
  struct Famliy famliy;
  // 创建一个儿子
  struct Person wang = {3, "wang", 1.67, 65};
  famliy.son = wang; // 可以通过 "变量.属性" 的方式来访问复杂类型中的某一个属性，并赋值
  
  // 创建母亲
  struct Person li = {4, "li", 4.54, 12};
  famliy.mother = li;
  
  // 创建父亲
  struct Person wang1 = {32, "wang1", 5.21, 23.5};
  famliy.father = wang1;
  ```

  ```
  // 3. 复杂类型组合成复杂类型（这里采用类 class，注意看 Famliy ）
  class Person {
  public:
      int age;
      char* name;
      float height;
      float weight;
  };
  
  class Famliy {
  /** 
   * 说明：这里加上了 public 关键字（keyword）。表示 public 后面跟着的属性都是可以被外界直接访问的。
   * 也就是说外界可以通过 "变量.属性" 的方式访问 son mother father 这些东西。
   *
   * 那为什么 struct 里面不用加 "public:"，是因为 struct 里面的属性默认都是 public，而 class 里面
   * 的属性默认都是外界不可访问的（private）的
  */
  public: 
      // Person 也是一个复杂类型
      Person son;
      Person mother;
      Person father;
  }; 
      
  // 创建一个变量，类型是 Famliy。并分别初始化 Famliy 里面的属性
  Famliy famliy;
  
  // 创建一个儿子
  Person wang;
  wang.age = 3;
  wang.name = "wang";
  wang.height = 1.67;
  wang.weight = 65;
  famliy.son = wang; // 可以通过 "变量.属性" 的方式来访问复杂类型中的某一个属性，并赋值
      
  // 创建母亲
  Person li;
  li.age = 4;
  li.name = "li";
  li.height = 1.87;
  li.weight = 12;
  famliy.mother = li;
      
  ...   
  ```
  <font color="red"> 注意对比下 2 和 3 里面的复杂类型的初始化有什么不同 </font>

  ```
  // 一份代码例子
  #include <iostream>
  
  struct Person {
      // 年龄
      int age;
      // 名字
      char *name;
      // 身高
      float height;
      // 体重
      float weight;
  };
  
  int main() {
      Person wang = {34, "wang", 2.5, 24};
      std::cout << "wang's age: " << wang.age << "wang's name: " << wang.name << std::endl;
  }
  ``` 
#### 函数（function）
- 数学中的函数
    ```
    z = f(x, y)
    自变量：x 和 y
    因变量：z
    函数体：f
    表示输入 x 和 y，经过一个变换 f，可以得到结果 z
  
    例如：z = x + y
    输入 x = 1 和 y = 2，经过加法变换 "+"，得到 z = 3  
    ```  
    <font color="red"> 本质：给定多个输入 X，经过一个变换 f，得到一个输出 Y </font>
    
- 编程语言中的函数（function）
    
    本质上，编程语言中的 function 和数学中的 function 是一样的，如下
    
    ```
    // 自变量：x（type = int） 和 y（type = int），又被称之为参数（argument）
    // 因变量：无名（type = int），又被称之为返回值（returned value）
    // 变换 f：花括号括起来的整个块，这个块可以有自己的名字，在这里被命名为 transform
    int transform(int x, int y) {
        return x + y;
    }
    ```
  
    编程语言中的 function 和数学中 function 的区别是：<font color="red">编程语言中的函数（function），对输入 X、输出 Y 做了类型（type）约束。 </font>
    
    另外，对于数学中的函数 z = f(x, y)，f(x, y) 能够拿来计算的数据只有 x 和 y，除此以外没有其他可以用来计算的数据，编程语言中的函数也是如此，如下：
    ```
    // 错误示范
    float add(float x, float y) {
        // 错误，因为 q 在输入参数（argument）里面找不到，程序不知道 q 是从什么地方来的。
        // 这也就意味着，函数体（花括号括起来的部分）能够使用的外界输入只有 x 和 y，没有其他的
        int a = x + q;
        return a;
    }
  
    // 正确示范
    float add(float x, float y) {
        int a =  x + y;
        return a;
    }  
    ```
    讲这个错误例子，是为了说明编程语言中的函数（function），能够使用的外界数据只有圆括号里面的参数（argument）。
    但有一种特殊情况，可以让函数使用不被包括在圆括号中的其他输入，这种特殊情况就是函数（function）的变种：方法（method）。
    
    ```
    // 本小节代码例子
    #include <iostream>
  
    struct Person {
        int age;
        char *name;
    };
  
    int add(int x, int y) {
        return x + y;
    }
  
    // 计算两个人的年龄和
    int calculateAgeSum(Person a, Person b) {
        return add(a.age, b.age);
    }
  
    int main() {
        Person wang = {12, "wang"};
        Person li = {24, "li"};
        std::cout << "age sum: " << calculateAgeSum(wang, li) << std::endl;
    }
    ```
  
#### 方法（method）  
当函数（function）和复杂类型（class 或 struct）绑定的时候，这种函数（function）我们称之为方法（method）

我们从两个方面来了解方法（method）：1、如何进行绑定；2、方法（method）相比普通的函数（function）有什么用？

- 如何绑定

    将函数（function）写在复杂类型（complex type）内部即可。
    
    ```
    // 第一个例子
    struct Person {
        // 年龄
        int age;
        // 名字
        char* name;
        // 身高
        float height;
        // 体重
        float weight;
  
        // 第一个方法
        int getAge() {
            return age;
        }
  
        // 第二个方法
        char* getName() {
            return name;
        }
    };
  
    // 创建 wang
    struct Person wang = {43, "wang", 24, 54.6};
    
    // 调用方法
    wang.getName();
  
    // 第二个例子
    class Person {
    private:
        // 年龄
        int age;
        // 名字
        char* name;
        // 身高
        float height;
        // 体重
        float weight;
     
    public:
        // 第一个方法
        int getAge() {
            return age;
        }
            
        // Attention：如果不明白为什么方法里面可以使用 age 这个变量，就继续看下一小节    
  
        // 第二个方法
        char* getName() {
            return name;
        }
    };
    
    // 创建 Li
    Person li;
    li.age = 13;
    li.name = "li";
    li.height = 45.6;
    li.weight = 32.1;
    
    // 调用方法
    li.getAge();
  
    ```

- 方法（method）相比函数（function）的优势（<font color="red">为什么要有方法这种东西？</font>）

    回顾 **如何绑定** 这一节中的代码例子，发现例子中的方法竟然使用了除了输入参数之外的数据！
    这岂不是和之前讲的 - **函数能够使用的外界数据，全部都在输入参数中（argument）中** - 这一观点相违背了吗？
    
    其实这就是方法（method）相比函数（function）的优势：方法可以使用与之绑定的复杂类型（complex type）内部的任意属性（attribute），如下
    
    ```
    class Person {
    private:
        // 年龄
        int age;
        // 名字
        char* name;
        // 身高
        float height;
        // 体重
        float weight;
    
    public:     
        // 注释：getAge() 和复杂类型（complex type）Person 绑定在了一起，所以 getAge() 可以使用 Person 内的任意变量
        int getAge() {
            // 注释：比如这里的 age，就是 Person 里面的属性
            return age;
        }
    };
    ```
    
#### 构造方法（construct method）

构造方法之所以拿出来单独讲，是因为它是<font color="red">一种特殊的方法（method）</font>，它没有明确的写明他的返回类型是什么。为了深入理解这一点，就接着往下看。

- 为什么要有 **构造方法** 这种东西？

    为了能够更加方便的（创建一个复杂类型变量/初始化一个变量）。
    
    我们先从一个简单的例子看起，这个例子是讲解如何初始化一个变量的
    
    ```
    // 声明一个类型为 int，名字为 a 的变量。并且用 1 去初始化 a 这个区域
    int a = 1; /* 变量 a 里面的值是确定的，并且为 1 */
  
    // 如果只是声明一个变量 a，而不去初始化呢？如下
    int a; /* 变量 a 里面的值是不确定的 */
    ```
  
    以上讲解的是基本类型（basic type）的变量初始化，下面引出复杂类型（complex type），并且利用结构体 struct 来说明
    ```
    struct Person {
        int age;
        char* name;
    };
  
    // 声明一个类型为 struct Person 的变量，并初始化它
    struct Person wang = {13, "wang"};
  
    // 同理，如果只是声明而不初始化，则 wang 里面的属性（attribute）值是不确定的
    struct Person wang; /* 此时 wang 里面的属性值都是不确定的 */
    // 但是我可以接下来用点的方式去重新给 wang 里面的属性（attribute）赋值
    wang.age = 1;
    wang.name = "wang";
  
    ```
    <font color="red">结论：上面写了两种初始化结构体的方法，很显然第一种用花括号的方式更加简洁</font>
        
    下面我们继续用 class 的方式去定义一个复杂类型（complex type），并初始化它
    
    ```
    class Person {
    public:
        int age;
        char* name;
    }
  
    Person wang; /* 没有初始化，所以此时 wang 里面的属性是不确定的 */
    wang.age = 1;
    wang.name = "wang";
    ```
 
    为什么这个例子没有像 struct 一样用花括号去初始化 wang ？是因为 C++ 的 class 不允许这种初始化方式。
    
    再看下面这个例子:
    
    ```
    class Person {
    private: // public -> private，一点小改动
        int age;
        char* name;
    }
  
    Person wang;
    wang.age = 1; // 严重错误！！！age 属性已经被定义为私有了，无法通过外部赋值了
    ```
    现在就连分别给每个属性赋值的方式也不允许了。
    
    为了找到一种更高效的给复杂类型（complex）的变量（variable）初始化/赋值的方式，我们就要回到讲解本节的目的：构造方法（construct method）。我们先看下面这个构造方法的例子：
    
    ```
    class Person {
    private:
        int _age;
        char* _name;
    
    public:
        // 这个方法就是 construct method，不过看起来它和之前说的普通 method 有点不太一样，比如：没有标明返回类型是什么。我们会在后面详细阐述这一点
        Person(int age, char* name) {
            _age = age;
            _name = name;
        }
  
        // 普通 method
        int getAge() {
            return _age;
        }
  
        // 普通 method
        char* getName() {
            reutrn _name;
        }
    }
  
    Person wang = Person(12, "wang");
    // wang 已经被构造方法给初始化了，所以下面这一行代码输出的 age 和 name 将不会是乱码
    std::cout << "Person age: " << wang.getAge() << "Person name: " << wang.getName() << std::endl;
    ```
    
    从字面意思理解，这里的 Person(12, "wang") 肯定是返回了一个什么东西让 wang 这个变量被初始化的。但从 Person(int, char*) 的定义来看，它并没有标注返回类型是什么，也没有在方法体（也就是花括号里面）里面写 return 语句。
    
    这就是构造方法（construct method）和普通方法（method）最大的不同，那就是：
    * 构造方法是有返回值的，只不过省略不写；
    
        如此可以写一个有返回值的构造函数，方便人理解，如下：
        ```
        // Case 1: 正常写法
        class Person {
        public:
            Person(int age, char* name) {
                _age = age;
                _name = name;
            }
          
        private:
            int _age;
            char* _name;
        }
      
        // Case 2: 给 construct method 加上返回值的写法。注意：这种写法在逻辑上和 Case 1 等价，但不会编译通过。这里之所以写出来是为了方便人理解
        class Person {
        public:
            // 试着用 function / method 的结构来分析这个函数
            Person Person(int age, char* name) {
                Person x;
                x._age = age;
                x._name = name;
                return x;      
            }
        
        private:
            int _age;
            char* _name;
        };
        
        // 这样就好理解多了，Person(int, char*) 实际上是创建了一个临时变量 x，并且给临时变量 x 里面的属性赋值，最后把 x 返回出去
        Person wang = Person(12, "wang");
        ```
        
        通过 Case 2 可以了解其实 construct method 是有返回类型的，这个返回类型就是 Person。并且这个返回的东西可以给 Person wang 赋值。由于返回类型和返回的数据都是固定是 Person，
        所以程序语言设计中，就把返回值给省略了，方便人书写。
        
    * 普通方法可以任意命名，但是构造方法的命名必须要和所绑定的复杂类型的命名相同；
    
        这个问题可以理解成，编译器是如何区分一个 method 是普通 method 还是 construct method，例子如下：
        ```
        class Person {
        public:
            /* 
             * 编译器知道这个 method 是 construct method，因为它的命名是 Person，和它所绑定的复杂类型 class Person 是同名的，
             * 并且也省略了返回值，所以编译器知道它是 construct method
             */
            Person(int age, char* name) {
                _age = age;
                _name = name;
            }
      
            /*
             * 又是一个 construct method，编译器也可以识别，理由同上
             */
            Person(int age) {
                _age = age;
            }
      
            /*
             * 第三个 construct method，编译器依然会认为这是一个 construct method
             */
            Person() {
                // 你看，方法体里面是空的 
            }
      
            /*
             * 错误例子 1：
             * 首先命名是 Person1212，和 class Person 的命名不一致，所以编译器认为这应该是一个普通 method。
             * 但这个普通 method 却没有返回值，因此编译器认定此处代码有语法错误。
             */
            Person1212(int age, char* name) {
                _age = age;
                _name = name;
            }
      
            /*
             * 错误例子 2：
             * 命名是 Person，和 class Person 命名一致，所以编译器认为这是一个 construct method。
             * 但是 construct method 的返回值是可以省略的，而这里却画蛇添足加了一个返回值，所以编译器认定是语法错误报错
             */
            Person Person(int age, char* name) {
                // 这里就不多解释了
            }
        private:
            int _age;
            char* _name;
        }
      
        // 利用 construct method 去（初始化变量/去给变量赋值）
        Person wang = Person(12, "wang");
        Person li = Person(4);
        Person hehe = Person();
      
        // 以上三种 construct method 的调用都可以，因为我写了三个不同的 construct method
        ```
   
    附上本节可运行代码   
    ```
    #include <iosteam>
    #include <cstring>
    
    class Person {
    public:
        Person() {}
  
        Person(int age, std::string name) {
            _age = age;
            _name = name;
        }
  
        Person(Person a, Person b) {
            _age = 1;
            _name = a.getName() + b.getName;
        }
  
        int getAge() {
            return _age;
        }
  
        std::string getName() {
            return _name;
        }
  
        void setAge(int age) {
            _age = age;
        }
  
        void setName(std::string name) {
            _name = name;
        }
  
    private:
        int age;
        std::string name;
    }
  
    class Famliy {
    public:
        Famliy(Person father, Person mother, Person me) {
            _father = father;
            _mother = mother;
            _me = me;
        }
  
        Person getFater() {
            return _father;
        }
  
        Person getMother() {
            return _mother;
        }
  
        Person getMe() {
            return _me;
        }
  
        std::string description() {
            return "father: " + _father.getName() + " _mother: " + _mother.getName + " me: " + _me.getName();
        }
  
    private:
        Person _father;
        Person _mother;
        Person _me;
    }
  
    int main() {
        // 组建家庭
        
        // 创建父亲
        Person father = Person(12, "wang");
    
        // 创建母亲
        Person mother = Person();
        mother.setName("li");
        mother.setAge(1);
  
        // 创建我
        Person me = Person(father, mother);
  
        // 组建家庭
        Famliy f = Famliy(father, mother, me);
        std::cout << f.description() << std::endl;
    }
    ```
    
程序为什么要这样改？
---

##### 为什么要用结构体

- 东西（变量、属性）到处乱放不好看
    
    程序最初会出现这样的代码：
        
    ``` 
        // grade -> 宝石的价值
        // "you get a xxx" -> 打印获得了什么种类的宝石
  
        if (number<=5){
            grade += 1;
            printf("you get a hupo!\n");
        } else if (number>10){
            grade += 15;
            printf("you get a zhuanshi!\n");
        } else {
            grade +=5;
            printf("you get a hongbaoshi!\n");
        }
    ```
    *grade*: 宝石的价值
    
    *"you get a xxx"*: 宝石种类的描述
    
    这段代码的本意是随机挖一个宝石，放到小王的包包里。这段代码当然可以正常运行，
    小王也能够知道他挖到了是什么宝石，到底是琥珀、钻石还是红宝石。
    
    但这样写的问题是容易乱。如果宝石种类不止三种呢？而是增加到了50种，那么是不是要写
    50 个 *if* 呢 ？又或者假如有其他地方也需要用到 *hupo* 和得分 *grade 1*，
    那岂不是要把 *hupo*、*grade 1* 又重新写一遍？结果就是，程序中到处都散乱的存放各种各样的宝石数据。
    
    还有，万一有一天 *hupo* 改名成中文 *琥珀*，那么程序中凡是出现 *hupo* 的地方都要手动修改成 *琥珀*，
    那这可也太麻烦了。
    
    所以我们有了这样一个原则：**如果有某一类数据 A，这个数据会被不同的地方访问，那么就把 A 集中写在一个地方**
    
- 有联系的东西最好是放在一起

    我觉得这一条说的比上一条更加直观，宝石的名字（比如*hupo*）和宝石的得分（比如 *grad 1*）在逻辑上是有联系的，
    他们同属于一类 -- *Gem*，他们都是 *Gem* 里面的属性。所以理所因当的要放在一起，而不是在程序里面写的到处都是。
    
    ```
    struct Gem {
        // 宝石种类
        char *kind;
        // 宝石价值
        int grade;
    }
    ```
  
    这就好比你有一个衣柜，你会把你的衣服、裤子袜子统统都放在衣柜里面，而不是把裤子扔在地上，
    衣服塞在鞋柜里。能把衣柜弄的整整齐齐的人，就一定能把结构体 *struct* 写的整整齐齐的。

##### 为什么没有想到要使用结构体 ？

- 不要总用线性思考方式（面向过程）！！！

    初学者会觉得写程序很难，是因为把思维限制死在按照顺序一行一行执行的代码上了，这就是顽固的线性思维。
    程序固然是一行一行往下执行的，这没错。但程序逻辑的组织并不仅仅只有线性组织。
        
    比如，当你看到小王冒险会挖出宝石 Gem 的时候，你会这样想：我应该在程序的某处给小王加上宝石的价值 grade，
    然后打印出小王获得了什么宝石。
        
        小王会获得一个宝石 -> 加上一个分数 -> 打印获取宝石事件。
            
    这样的思考方式就显然忽略了宝石 Gem 作为一个逻辑实体的存在，导致在实际编写程序的时候，到处都是宝石 *kine* 和 *grade* 的定义。
    等到程序复杂了起来，就发现写的乱糟糟的，各种属性到处乱放，时间久了自己都看不懂自己写的是什么了。
        
    而对于有经验的人，他会这样想：
        
        小王会获得一个宝石 -> 说明程序里有"宝石"和"人"这两种概念。
            
    这种思维方式就是面向对象，它把程序中可能用到的数据，抽象出一个一个逻辑实体，自然而然的就会写出如下代码：

    ```
        struct Gem {
            // 宝石种类
            char *kind;
            // 宝石价值
            int grade;
        }
        
        struct Person {
            // 人的名字，在这里应该是小王
            char *name = "wang";
            // 已获得的宝石价值
            int value;
        }
    ```
    
    这样的好处就是：凡是和"宝石"，"人"相关的概念都集中定义在一起，如果有其他地方要使用的话，
    直接引用就好了。未来如果想额外增加一些数据，也可以直接在这里增加，而不是在程序里乱找。
    