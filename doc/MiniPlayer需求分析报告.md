# 需求分析报告

### 软件功能需求
- 基本的播放器功能(声音未作处理,为无声)
- 可以进行暂停,快退(5s),快进(5s)
- 可以在播放完后重放

### 开发需求
#### 环境
跨平台设计,利用Qt和C++对跨平台性质,支持同时在Windows下和Ubuntu下运行

#### 框架
MVVM框架,解除耦合,实现独立开发

#### 持续集成
利用Trival CI持续继承,实现自动build, test, release

#### 单元测试
对Model进行单元测试,以及在每轮迭代之后(App层组装完成),对整个程序进行整体测试