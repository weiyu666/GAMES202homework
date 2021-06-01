# GAMES202homework
主要是学习闫老师的GAMES202高质量实时渲染完成的大作业

### RenderDoc调试webgl:

用到了webgl所以需要webgl抓帧调试,但是当前shader的调试暂时不支持~

[RenderDoc 调试web]: https://blog.csdn.net/chenweiyu11962/article/details/115400725



### homework0

作业0主要是实现的Blinn-Phong 着色模型 ，最主要是的环境搭建测试熟悉202的框架等等；

------

### homework1

作业1主要是在Blinn-Phong 着色模型基础上实现阴影，通过shadow map实现硬阴影、Soft 阴影PCF算法过滤、软硬阴影PCSS；

------

### homework2

作业2主要是在实现PRT(Precomputed Radiance Transfer)本次作业的工作主要分为两个部分：cpp 端的通过一种预计算方法，该方法在离线渲染的 Path Tracing 工具链
中预计算 lighting 以及 light transport 并将它们用球谐函数拟合后储存；以及在 WebGL框架上使用预计算数据部分;
1、基于球谐函数的预计算辐射传输
2、分为有阴影与无阴影的
3、加分项旋转
------

### homework3
作业三主要即考虑直接光照也考虑间接光照，最主要是实现全局光！
• 实现对场景直接光照的着色 (考虑阴影)。
• 实现屏幕空间下光线的求交 (SSR)。
• 实现对场景间接光照的着色。


