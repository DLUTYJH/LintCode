# ROSE Compiler 从源码安装过程


---

ROSE编译器框架，是由LLNL开发的，是一种开源软件编译器基础架构，可用于多种源语言生成源到源分析器和翻译器，ROSE使用了Edison Design Group的C ++前端。但是EDG作为商业的前端，所以在ROSE构建过程中，自动下载封装的EDG二进制压缩包。

>*  相关参考资料
>*  ROSE的软件依赖
>*  依赖软件的安装过程
>*  boost的安装过程
>*  ROSE的配置和构建过程
>*  总结

---

## 一.相关参考资料

### 1.[ROSE 维基百科介绍](https://en.wikipedia.org/wiki/ROSE_(compiler_framework))
### 2.[ROSE主页](http://rosecompiler.org/ROSE_HTML_Reference/index.html)
### 3.[ROSE github]github提供开发版本和发布版本，地址分别为：
[DevelopmentRepository](https://github.com/rose-compiler/rose-develop)
[Release Repository](https://github.com/rose-compiler/rose)
### 4.[ROSE wikibook介绍](https://en.wikibooks.org/wiki/ROSE_Compiler_Framework/Print_version#EDG_4.x_internal_branch)
### 5.[ROSE编译器框架/虚拟机映像](https://en.wikibooks.org/wiki/ROSE_Compiler_Framework/Virtual_Machine_Image)
### 6.[ubuntu 14.04 LTS 安装boost](http://valleylord.github.io/post/201601-boost-install/)
### 7.[boost 1.61.0 版本下载](https://sourceforge.net/projects/boost/files/boost/1.61.0/boost_1_61_0.tar.gz/download)

---

## 二.ROSE的软件依赖
仅仅列出必须部分软件依赖，完整的软件依赖请参考，[ROSE Software dependencies](http://rosecompiler.org/ROSE_HTML_Reference/group__software__dependencies.html)。

### ROSE的软件依赖
|软件组件|支持版本|软件组件作用|
|--------|--------|------------|
|git     |任何最新版本|用于将ROSE版本库克隆到本地计算机|
|wget    |任何最新版本|用于下载EDG二进制tarball|
|GNU Compiler Collection        |GCC-4.2.4 through 4.8.4            |编译ROSE|
|GNU autotools|automake-1.11.1或更高版本; autoconf-2.59或更高版本; libtool-1.5.6或更高版本|Automake，autoconf和libtool用于配置ROSE并生成makefile|
|CMake|2.8.12 or later|配置ROSE并生成makefile|
|Flex and bison|任何最新版本|生成词法分析器和解析器的代码|
|Java Development Kit|Any version 7|使用cmake配置ROSE时，即使禁用Java和Fortran前端也需要JDK|
|Python|3|使用autoconf时，无论是否启用此类支持，ATME都支持ROSE|
|boost|1.51至1.61，除1.54外|ROSE和/或ROSE使用的软件需要以下Boost库：hrono, date_time, filesystem, iostreams, program_options, random, regex, signals, system, thread, and wave.|

**注意：    CMake和GNU autotools二者只需要一个即可。**

---

## 三.依赖软件的安装过程
###1.[git](https://git-scm.com/)
以root运行:  `apt-get install git`
###2.[wget](https://www.gnu.org/software/wget/)
以root运行:  `apt-get install wget`
###3.[GNU Compiler Collection](https://gcc.gnu.org/)
以root运行:  `apt-get install build-essential`，(执行该命令后已经包含boost安装相关的依赖) , `apt-get install g++ gfortran`
**注意： g++ --version #查看版本信息是否为： 4.8**
###4.[CMake](https://cmake.org/)
以root运行:  `apt-get install cmake` 
###5.[Flex](http://flex.sourceforge.net/) and [bison](https://www.gnu.org/software/bison/)
以root运行:  `apt-get install flex bison`
###6.[Java Development Kit]
以root运行:  `apt-get install default-jdk` , ROSE官网官网说分别安装JVM和JDK，但是JDK已经包含了JVM，所以经过测试后证实，通过apt安装默认的Java7 版本即可。(或许当对Java源码分析的时，需分别从官网下载后安装，没经过实验尝试。)
###7.[Python](https://www.python.org/)
以root运行:  `apt-get install python3-dev`

---

## 四.boost的安装过程
boost安装尤为重要，也最容易出错误。将从以下四个方面进行阐述：
###1. 版本选择 
ROSE官网明确约定，ROSE配置支持的版本是：1.51至1.61，除1.54，所以在安装过程中该选择正确的版本进行安装，否则ROSE配置是将不支持该版本。安装过程中选择了[boost 1.61.0](https://sourceforge.net/projects/boost/files/boost/1.61.0/boost_1_61_0.tar.gz/download)版本。
###2. 第三方依赖
以root运行:  `apt-get install mpi-default-dev libicu-dev python-dev python3-dev libbz2-dev zlib1g-dev` ,如果按照以上的依赖软件顺序依次安装，可以跳过这个步骤。
###3.安装
I.  下载`boost_1_61_0.tar.gz`，解压后，得到一个文件夹`boost_1_61_0`,打开终端，在终端依次执行一下的命令：
` cd boost_1_61_0/ `

` ./bootstrap.sh --prefix=$BOOST_ROOT --with-libraries=chrono,date_time,filesystem,iostreams,program_options,random,regex,serialization,signals,system,thread,wave`

该命令执行boost中的脚本bootstrap.sh，默认使用gcc编译工具;并指定安装路径--prefix=` $BOOST_ROOT `($BOOST_ROOT为安装路径，测试中使用的路径是： /opt/boost/1.61.0 ); 通过--with-libraries 来指定编译的库，可以指定为all ，但是编译所需时间就比较长。

` ./b2 --prefix=$BOOST_ROOT -sNO_BZIP2=1 install `
该命令是安装boost，通过--prefix=` $BOOST_ROOT ` 指定安装路径($BOOST_ROOT为安装路径，测试中使用的路径是： /opt/boost/1.61.0) 

II. 配置环境变量
` export LD_LIBRARY_PATH=/opt/boost/1.61.0/lib:$LD_LIBRARY_PATH `
确保LD_LIBRARY_PATH环境变量包含boost的“lib”目录。

###4.测试 
执行命令 ` g++ -I /opt/boost/1.61.0/include test.cpp -o test  `,test.cpp包含以下的测试代码，并打印出boost相关的版本信息，即安装成功。也可以不通过-I 选项指定boost库路径，可以在` /usr/loacl//include  `添加boost库的软链接。
```C++
#include <string>
#include <iostream>
#include <boost/version.hpp>
#include <boost/timer.hpp>
using namespace std;
int main()
{
    boost::timer t;
    cout << "max timespan: " << t.elapsed_max() / 3600 << "h" << endl;
    cout << "min timespan: " << t.elapsed_min() << "s" << endl;
    cout << "now time elapsed: " << t.elapsed() << "s" << endl;
    cout << "boost version" << BOOST_VERSION <<endl;
    cout << "boost lib version" << BOOST_LIB_VERSION <<endl;
    return 0;
}
```

---

##五.ROSE的配置和构建过程
测试过程中使用的是：ROSE发布的版本，而不是开发版本，并使用` GNU autotools `进行配置和构建。以下是三个自定义变量的说明：
` $ROSE_SRC ` 是保存ROSE源代码的顶级目录，即： /home/answer/rose (测试本机上的路径，安装过程中许指定自己的路径)
` $ROSE_BLD `是您创建的这些指令的构建目录,(可以任意指定，本机指定的路径是: /opt/bulid_rose )
` $BOOST_ROOT `是boost的安装路径，在该测试环境中是："/opt/boost/1.61.0"

**注意： 在配置和构建过程中，保持连网，可以自动下载封装的EDG二进制压缩包，可以减免很多的麻烦。**

###1. 将ROSE源代码从远程库中克隆下来 ` git clone https://github.com/rose-compiler/rose `

###2. 使用` GNU autotools `进行配置
在终端中运行，` $ROSE_SRC `目录中的` ./build `，此脚本不会引用任何参数，并修改ROSE源代码树以准备使用GNU autoconf工具。

确保LD_LIBRARY_PATH环境变量包含boost的“lib”目录：
` export LD_LIBRARY_PATH=/opt/boost/1.61.0/lib:$LD_LIBRARY_PATH `

在同一个终端下依次执行以下的命令行，构建ROSE。--prefix=$HOME/my-rose-installation参数指定了ROSE的安装路径，本机中的安装路径是：“/opt/my_rose”.
` cd $ROSE_BLD `
` $ROSE_SRC/configure --prefix=$HOME/my-rose-installation --enable-languages=c,c++ --with-boost=$BOOST_ROOT `

###3.ROSE 的构建
运行` cd $ROSE_BLD `，然后运行` make install-rose-library `，构建和安装ROSE，并注意构建和安装过程中打印的日志，以查看确定发生何种错误和是否构建成功。

---

## 六.总结
经过多次尝试，终于从源码成功的构建和安装了ROSE，其过程遇到很多的错误，对这些错误做以下的总结：
###1.boost的安装
boost的安装是所有软件依赖组件中最为麻烦的，也是最容易出现错误的。首先，就是版本的选择一定要符合官网的要求，` 1.51至1.61，除1.54外 `，在安装过程中我尝试过1.64和1.50两个版本，都在ROSE配置过程出现错误，分别是：不支持boost1.64版本和boostlibrary 版本必须大于1.51，所以一定注意boost版本的选择。其次ROSE官网给出的安装boost的步骤中，下载boost版本就是1.50,需要特别留意。

###2.LD_LIBRARY_PATH环境变量
在终端环境下，` echo $LD_LIBRARY_PATH ` 打印为空，通过` env `命令查看，无法找到该环境变量。在安装配置过程中我在/etc/profile文件中添加LD_LIBRARY_PATH环境变量，指定source命令后，通过echo能打印，但是在另一个终端中打印又为空，配置没有起作用。所以在ROSE配置构建过程中，遇到线程库的错误。所以，该首先执行 ` export LD_LIBRARY_PATH=/opt/boost/1.61.0/lib:$LD_LIBRARY_PATH ` ，然后在本终端下继续配置构建命令。

###3.测试boost是否安装成功
测试的过程中，直接执行` g++ test.cpp -o test `，结果产生错误：没有该文件或者目录，虽然也在/etc/profile 文件中配置了环境变量CPLUS_INCLUDE_PATH,但是遇到了和环境变量LD_LIBRARY_PATH类似的错误。造成该错误的原因主要是:第一对g++命令的使用不够熟练，第二就是环境变量的问题。后来通过 -I选项或者在/usr/local/include中添加软链接，解决了该问题。

###4.EDG的安装
确保在ROSE的配置构建过程中连网，就能自动下载封装的EDG二进制压缩包。如果出现关下载EDG二进制压缩包的错误，请参照[EDG安装](http://rosecompiler.org/ROSE_HTML_Reference/group__installing__edg.html)。



















