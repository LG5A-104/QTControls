V20150625更新
1：集成QSS文件到资源文件，无需拷贝。
2：增加AppInit类，引入后无需对每个窗体进行鼠标按下松开拖动事件的重载，只需要将界面增加属性CanMove属性为真即可。this->setProperty("CanMove", true);
3：样式下拉框改为中文显示。

特点：
1：无边框窗体，自定义标题栏，鼠标拖动，大小缩放，双击切换。
2：除了少量的几个图片资源外，几乎使用QSS写完所有颜色样式控制。
3：自定义一个QMessageBox对话框，自动换行显示提示信息，可以很方便的调用。
信息框：myHelper::ShowMessageBoxInfo
询问框：myHelper::ShowMessageBoxQuesion
错误框：myHelper::ShowMessageBoxError
4：使用fontawesome图形字体库，将互联网的优秀资源应用于QT中。
5：公开源码，可以任意随意使用。
6：QT各个版本都可以编译通过，亲测无误。
7：自带提供了7种样式黑色、蓝色、灰色、天蓝色等风格供选择，可以自由更改QSS文件夹下的样式，也可以自己增加一些样式。 
如果有更好的建议，非常欢迎提出来！ 

可执行文件CSDN下载地址:http://download.csdn.net/detail/feiyangqingyun/8277395
编译后将源码下的QSS目录复制到编译后的bin目录下即可。
