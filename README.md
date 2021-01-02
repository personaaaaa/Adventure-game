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

##### 类型
- 基本类型
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
- 复杂类型
 
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
  Person son = {3, "wang", 1.67, 65}; // 花括号里面的数据，按照顺序依次初始化 son 里面的属性
  Person mother; // 这里没有使用花括号去初始化 mother 里面的属性，因此属性的值是不确定的。
  
  
  ```
 
  ```
  // 2. 复杂类型组合成复杂类型（这里采用结构体 struct ）
  struct Famliy {
      // Person 也是一个复杂类型
      Person son;
      Person mother;
      Person father;
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
  // 3. 复杂类型组合成复杂类型（这里采用类 class ）
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
    