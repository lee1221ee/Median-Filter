# C++ 原始碼：Median Filter
中值濾波是一種非線性數字濾波器技術，經常用於去除圖像或者其它信號中的雜訊。

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](https://i.imgur.com/VDGcnN1.png)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;▲ 左圖有鹽和胡椒雜訊，右圖已經過MF消除雜訊(圖截自[mathworks](https://www.mathworks.com/help/images/ref/medfilt2.html))


中值濾波的基本原理是把數字圖像或數字序列中一點的值，用該點的一個鄰域中各點值的中值代替。

The basic idea is simple — order elements and take the middle one.


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](https://i.imgur.com/kiPUFlc.gif)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;▲ Taking the median.

## Median filter algorithm
1. Place a window over element;
2. Pick up elements;
3. Order elements;
4. Take the middle element.

## 1D median filter
在一維數列中，依序以某點為中心套用遮罩(mask)或視窗(window)。

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](https://i.imgur.com/RcwH36S.gif)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;▲ Window or mask of size 5 in 1D.

### Function of algorithm
> 對於程式碼詳細解釋，可參閱 [README](http://www.librow.com/articles/article-1)

{%gist SiNcSaD/54e3a51fcfa24caa9d02e1d354ea6b12%}

### Improved function
所有種類的遮罩濾波器都會有一個問題，就是==邊緣處理 (edge treating)==。
If you place window over first (last) element, the left (right) part of the window will be empty.
為了填滿這個空隙 (gap) ，數列 (signal) 將需要擴充 (extended)。

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](https://i.imgur.com/dZPojWF.gif)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;▲ Signal extension.

{%gist SiNcSaD/19d5177825b27cec9d71da4296c34422%}

## 2D median filter
In two dimensions,median filter has 2D window.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;!![](https://i.imgur.com/M7U2N1B.gif)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;▲ Window or mask of size 3×3 in 2D.

### Function of algorithm
{%gist SiNcSaD/5293929299f5df2f60aa9abbd5f24d36 %}

### Improved function

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](https://i.imgur.com/inUZ1f6.gif)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;▲ Image extension.

{%gist SiNcSaD/9c98de8a5b7ab21f7cede113ec725559 %}

## 主程式(main)
透過 #ifdef 決定編譯與執行1D或者2D區塊的程式碼。
```shell=
#define dim_1D
```
### 1D Median Filter 
```
signal_1D elements:

 16, 23, 13, 14, 28, 20, 12, 22, 25, 11,  6, 17,  1, 10, 18,

result elements:

 16, 16, 16, 20, 14, 20, 22, 20, 12, 17, 11, 10, 10, 17, 10,
```
### 2D Median Filter
```
signal_2D elements:

   64,    2,    3,   61,   60,    6,    7,   57,

    9,   55,   54,   12,   13,   51,   50,   16,

   17,   47,   46,   20,   21,   43,   42,   24,

   40,   26,   27,   37,   36,   30,   31,   33,

   32,   34,   35,   29,   28,   38,   39,   25,

   41,   23,   22,   44,   45,   19,   18,   48,

   49,   15,   14,   52,   53,   11,   10,   56,

    8,   58,   59,    5,    4,   62,   63,    1,

result elements:

   55,    9,   12,   54,   51,   13,   16,   50,

   17,   46,   46,   21,   21,   42,   42,   24,

   26,   40,   37,   27,   30,   36,   33,   31,

   32,   34,   34,   29,   30,   36,   33,   31,

   34,   32,   29,   35,   36,   31,   31,   33,

   34,   32,   29,   35,   38,   28,   25,   39,

   41,   23,   23,   44,   44,   19,   19,   48,

   15,   49,   52,   14,   11,   53,   56,   10,
```
{%gist SiNcSaD/bd755694cd63e4f2155b6e9ad3dbdb50 %}

**<font size=6>以下有 Source Code 連結
有幫助到的話，幫我點個 Star :laughing: </font>**

[![](https://i.imgur.com/tR17ixG.png)](https://github.com/SiNcSaD/Median-Filter)
