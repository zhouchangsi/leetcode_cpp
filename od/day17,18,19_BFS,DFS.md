# 第十七/十八/十九天

第十七天直播地址：https://uha.h5.xeknow.com/sl/1SY4PM

第十八天直播地址：https://ntpkq.h5.xeknow.com/sl/4XJR3

第十九天直播地址：https://ntpkq.h5.xeknow.com/sl/1oGpd8

## 直播课件

[第十七十八十九天-DFS/BFS-华为OD培训.pdf](https://og7kl7g6h8.feishu.cn/file/VPUNbu8u8o2LaHxrrwnchs76nae)

## DFS/BFS

### 前置问题

- [【模拟】2023B-统计监控](https://og7kl7g6h8.feishu.cn/docx/IComdGbRro179rxj3XRcuKoenXt)
    

### 二维矩阵表示图（岛屿问题）

- [LC200. 岛屿数量](https://og7kl7g6h8.feishu.cn/docx/E4pSd20NEoJK2Ux3BrjcncKbn1d)
    
- [LC695. 岛屿的最大面积](https://og7kl7g6h8.feishu.cn/docx/TA8ZdN7Hmo8g3excejmcJ2vMnWf)
    
- [【DFS/BFS】2023Q1A-开心消消乐](https://og7kl7g6h8.feishu.cn/docx/Ss9QdEWYaooSdXx3ykbc4dHBnSe)
    
- [【DFS/BFS】2023B-寻找最大价值的矿堆](https://og7kl7g6h8.feishu.cn/docx/ZLfNdmszho3j44x8Z4FcKyubnxe)
    

### **邻接矩阵**表示图

- [LC547. 省份数量](https://og7kl7g6h8.feishu.cn/docx/A9PAdE2skoyThIxjVt5cA0hXnUh)
    
- [【DFS/BFS】2023Q1A-Linux发行版的数量](https://og7kl7g6h8.feishu.cn/docx/QJrYdFGcro67xfxhuy6cpanMnog)
    

### 邻接表表示图

- [LC841. 钥匙和房间](https://og7kl7g6h8.feishu.cn/docx/M9tadV4OmoY2l5xLBBzcf8hun4m)
    

1. 注意比较DFS和BFS的异同。
    
    1. **相同之处**：这两种算法都属于在树形结构或者图的搜索算法，能够访问所有的节点/位置
        
    2. **不同之处**：
        
        1. DFS像侦察兵一样一直优先往深处搜索；BFS像军队一样铺展开来搜索
            
        2. DFS通常需要借助用递归实现，本质上是用到了编译栈；BFS通常需要借助队列来辅助实现
            
        3. BFS有层的概念（level），有时候也称为波纹法，通常可以用来搜寻最短路径
            
        4. 对于二叉树而言，DFS有先序、中序、后序三种遍历方式，但对于图而言通常没有这种分类；BFS在二叉树中也称为层序遍历。
            
2. 图可以有多用多种方式来表示，譬如**二维矩阵、邻接矩阵、邻接表**等等，但本质上都大同小异。不要拘泥于图的表示形式，重点还是要理解DFS和BFS的过程以及万能模板。
    
3. DFS和BFS的应用很多，不仅仅在这种显式的图的问题中可以用到，也可以在一些生成问题用到。这是因为可以将字符串/数组的生成过程写成一个树形结构，要注意融会贯通。
    

## 多源BFS

- [LC994. 腐烂的橘子](https://og7kl7g6h8.feishu.cn/docx/HhYfdYMjboE1a2xXGD2clu1EnZm)
    
- [【BFS】2023Q2B-火星改造](https://og7kl7g6h8.feishu.cn/docx/HMGgdM8bzouRQsxNMQicf1fKncb)
    

## 拓扑排序

- [LC207. 课程表](https://og7kl7g6h8.feishu.cn/docx/SJMedkcxrolGmkx7IsScvm6qn5d)
    
- [【BFS】2023Q1-快速开租建站](https://og7kl7g6h8.feishu.cn/docx/QpfMdpJn2oDJskxdQLkcHpMonAd)
    

一般而言，包含**最短路径、最近出口等关键词**的题目，**用BFS**解决要比用DFS更优。

## 作业

- LC463. 岛屿的周长
    
- LC733. 图像渲染
    
- [【DFS/BFS】2023Q2-广播服务器](https://og7kl7g6h8.feishu.cn/docx/Y55Wdg27voWjgNxTFfqci2Sunzg)
    
- [【DFS/BFS】2023Q1A-机器人活动区域](https://og7kl7g6h8.feishu.cn/docx/IQn7dOD6GojFeGxNuF5c2oPdnIb)
    
- [LC210. 课程表II](https://og7kl7g6h8.feishu.cn/docx/NVzxdJ3uwoMMKWxFef7cW1uDnuh)
    
- LC1136. 并行课程（会员）
    
- LC1926. 迷宫中离入口最近的出口
    
- [【BFS】2023Q2-士兵突击](https://og7kl7g6h8.feishu.cn/docx/EEzsdMClwoT7j7xOH9rcUhgLnyV)
    
- [【DFS+树形DP】2023Q2-获取食物游戏](https://og7kl7g6h8.feishu.cn/docx/PoERdvGHNo9XUixVa89cLJJvnYd)
    

  

|数据表示方式|二维矩阵|关联矩阵|邻接表|
|---|---|---|---|
|计算连通块数目|[LC200. 岛屿数量](https://og7kl7g6h8.feishu.cn/docx/E4pSd20NEoJK2Ux3BrjcncKbn1d)<br><br>[【DFS/BFS】2023Q1A-开心消消乐](https://og7kl7g6h8.feishu.cn/docx/Ss9QdEWYaooSdXx3ykbc4dHBnSe)|[LC547. 省份数量](https://og7kl7g6h8.feishu.cn/docx/A9PAdE2skoyThIxjVt5cA0hXnUh)<br><br>[【DFS/BFS】2023Q2-广播服务器](https://og7kl7g6h8.feishu.cn/docx/Y55Wdg27voWjgNxTFfqci2Sunzg)||
|计算连通块大小|[LC695. 岛屿的最大面积](https://og7kl7g6h8.feishu.cn/docx/TA8ZdN7Hmo8g3excejmcJ2vMnWf)<br><br>[【DFS/BFS】2023B-寻找最大价值的矿堆](https://og7kl7g6h8.feishu.cn/docx/ZLfNdmszho3j44x8Z4FcKyubnxe)<br><br>[【DFS/BFS】2023Q1A-机器人活动区域](https://og7kl7g6h8.feishu.cn/docx/IQn7dOD6GojFeGxNuF5c2oPdnIb)|[【DFS/BFS】2023Q1A-Linux发行版的数量](https://og7kl7g6h8.feishu.cn/docx/QJrYdFGcro67xfxhuy6cpanMnog)||
|计算最短路径<br><br>（只用BFS）|[LC994. 腐烂的橘子](https://og7kl7g6h8.feishu.cn/docx/HhYfdYMjboE1a2xXGD2clu1EnZm)<br><br>[【BFS】2023Q1A-计算网络信号](https://og7kl7g6h8.feishu.cn/docx/Jojed0ydKoqLStxG5d2cn51pnch)<br><br>[【BFS】2023Q2B-火星改造](https://og7kl7g6h8.feishu.cn/docx/HMGgdM8bzouRQsxNMQicf1fKncb)<br><br>[【BFS】2023Q2-士兵突击](https://og7kl7g6h8.feishu.cn/docx/EEzsdMClwoT7j7xOH9rcUhgLnyV)|||
|判断是否能够遍历<br><br>(无依赖)|||[LC841. 钥匙和房间](https://og7kl7g6h8.feishu.cn/docx/M9tadV4OmoY2l5xLBBzcf8hun4m)|
|判断是否能够遍历<br><br>(有依赖，拓扑排序)|||[LC207. 课程表](https://og7kl7g6h8.feishu.cn/docx/SJMedkcxrolGmkx7IsScvm6qn5d)<br><br>[LC210. 课程表II](https://og7kl7g6h8.feishu.cn/docx/NVzxdJ3uwoMMKWxFef7cW1uDnuh)<br><br>[【BFS】2023Q1-快速开租建站](https://og7kl7g6h8.feishu.cn/docx/QpfMdpJn2oDJskxdQLkcHpMonAd)|