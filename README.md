# GAMES202homework
主要是学习闫老师的GAMES202高质量实时渲染完成的大作业

### RenderDoc调试webgl:

用到了webgl所以需要webgl抓帧调试,但是当前shader的调试暂时不支持~

[RenderDoc 调试web]: https://blog.csdn.net/chenweiyu11962/article/details/115400725



### homework0

作业0主要是实现的Blinn-Phong 着色模型 ，最主要是的环境搭建测试熟悉202的框架等等；

运行效果：

![运行效果图](https://user-images.githubusercontent.com/22174508/136559760-6b3960e5-a84b-4c88-8d44-afe45b8a5631.png)


------

### homework1

作业1主要是在Blinn-Phong 着色模型基础上实现阴影，通过shadow map实现硬阴影、Soft 阴影PCF算法过滤、软硬阴影PCSS；

PCSS效果图：

![PCSS_01](https://user-images.githubusercontent.com/22174508/136558831-2e129ace-8404-422a-9d17-9c8591a13c1e.png)


PCF:


![PCF_01](https://user-images.githubusercontent.com/22174508/136558828-97e12088-3784-4a50-b451-3d2222136367.png)

SM:

![SM_02](https://user-images.githubusercontent.com/22174508/136558830-98b1e75f-6dfb-4da5-bf39-ff3fee62e596.png)

------

### homework2

作业2主要是在实现PRT(Precomputed Radiance Transfer)本次作业的工作主要分为两个部分：cpp 端的通过一种预计算方法，该方法在离线渲染的 Path Tracing 工具链
中预计算 lighting 以及 light transport 并将它们用球谐函数拟合后储存；以及在 WebGL框架上使用预计算数据部分;
1、基于球谐函数的预计算辐射传输
2、分为有阴影与无阴影的
3、加分项旋转

PRT球谐函数间接环境光：

![、PRT_Shadowed _my](https://user-images.githubusercontent.com/22174508/136558910-e8433723-85da-4f63-aa9a-397f76a69241.png)



------

### homework3
作业三主要即考虑直接光照也考虑间接光照，最主要是实现全局光！
• 实现对场景直接光照的着色 (考虑阴影)。
• 实现屏幕空间下光线的求交 (SSR)。
• 实现对场景间接光照的着色。

全局光照效果图：


![立方体间接光3](https://user-images.githubusercontent.com/22174508/136558945-cbc17249-42c8-4f66-8e6a-1c2e6d44d9be.jpg)

![山谷间接光](https://user-images.githubusercontent.com/22174508/136558955-b07978ca-8bf7-47ce-acce-c0540b3945d9.jpg)


------

### homework4
作业四由于BRDF忽略微平面间的多次弹射，导致了材质的能量损失！使用Kulla-Conty BRDF 模型来近似能量守恒，BRDF 的补偿项 fms，而 fms的计算需要 E(µ) 和 Eavg 两个前置变量
分两个部分：
• 在离线端 (lut-gen 文件夹中) 预计算 E(µ) 和 Eavg。 
• 在实时端 (homework4 文件夹中) 通过查询预计算数据构建 BRDF 的补偿项；
当然这都是基于PBR的！

PBR效果图：
无补充光
![0812185950](https://user-images.githubusercontent.com/22174508/136559017-f89c8ff4-af80-47e1-81e8-1d2d2b751fa0.png)


使用Kulla-Conty BRDF 模型补偿项 
![reslut](https://user-images.githubusercontent.com/22174508/136559037-e9b510ca-0969-403f-afa6-60097812ea30.png)


### homework5

------

作业5实现一个简单的实时光线追踪的降噪方法。光线追踪的渲染结果，G-Buffer 及其他相关信息会以放在 http://games-cn.org/forums/topic/zuoye5fabugonggao/
的examples文件夹中大概1.3G；这次主要是解决怎么样降噪的问题！
作业分为三部分：
单帧图像的降噪，计算 motion vector，累积帧间信息；

光追去噪效果图：
![微信截图_20211008204459](https://user-images.githubusercontent.com/22174508/136559517-067527c2-1c8e-4bda-9eeb-85303b2da993.png)

![微信截图_20211008204546](https://user-images.githubusercontent.com/22174508/136559369-17a68cc2-949d-487c-85a8-aa433f175368.png)


### Games202成绩证书~
------
![games202en](https://user-images.githubusercontent.com/22174508/171464844-1c98f155-5fef-4564-b583-9a1c06fe2087.png)
![games202结业](https://user-images.githubusercontent.com/22174508/171464893-be18ea27-8d98-41a4-8243-c0f6e33e77a7.png)





