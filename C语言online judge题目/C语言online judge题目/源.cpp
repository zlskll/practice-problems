#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//1.数一个数的二进制位有多少个1
//数二进制位当然是直接对位进行操作
// 法①可以使用左移右移
//int main() {
//	int a = 15;  //0000 1111
//	           //1:0000 0001
//	int count = 0;
//	for (size_t i = 0; i < 32; i++) {//32位检索一遍
//		if ( ((a >> i) & 1 )== 1) {//最后一位为1
//			count++;
//		}
//    //err：a>>1没有对本身进行修改，它有用的部分是作为返回值，所以不能单独拎出来
//	// a >> 1;//然后右移
//	}
//	printf("%d", count);
//
// }
 
                  //法②：根据左移右移的效果也能干
//int main() {
//	int a = 15;  //0000 1111
//	//1:0000 0001
//	int count = 0;
//	while(a){//a一直除到1的话1/2=0,就结束循环，也可以for32次
//		if (a % 2 == 1) {//最后一位是1
//			count++;
//		}
//		a /= 2;//移动到下一位
//	}
//	printf("%d", count);
//
//}

                  //  法③：妙手
//int main() {
//	int a = 15;  //0000 1111
//	//1:0000 0001
//	int count = 0;
//	//a:15---1111
//	//a-1:14---1110
//	//a & (a-1)---1110  效果是在原来的基础上删去最低的1,结果是去0以后的值
//	while (a) {//去掉0以后成为了0，说明没有1了
//		a = a & (a - 1);
//		count++;//只要循环能进行，就加一次
//	}
//	printf("%d", count);//太妙了我草
//
//}
 

//2.判断一个数是不是2的n次方
//int main() {
//	int k = 0;
//	int flag = 0;
//	scanf("%d", &k);
//	2的n次方，跟二进制权重挂上勾了
//	一个数是2的n次方，就说明它的二进制位只有一个1
//	所以只要k&(k-1)==0，就说明&之前是只有一个1
//	for (size_t i = 0; i < 32; i++) {
//		if ((k & (k - 1)) == 0) {
//			printf("Yes");
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0) {
//		printf("No");
//	}
//
//
//	return 0;
//}

//3.计算两个int类型的m、n的二进制位有多少个不同
  //法①：用左移操作符同步比较
//int main() {
//    int m = 1999;
//    int n = 2299;
//    int count = 0;
//    for (size_t i = 0; i < 32; i++) {
//        if (((m >> i) & 1) != ((n >> i) & 1)) {
//            count++;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
// }

                   //法②：用按位异或符号^,^:如果一样就是0，不一样就是1
   //^以后的结果，去看这个结果有多少个1，调用一下上面那个函数就可以了
//int Numberof1(int a) {
//	  //0000 1111
//	//1:0000 0001
//	int count = 0;
//	while(a){//a一直除到1的话1/2=0,就结束循环，也可以for32次
//		if (a % 2 == 1) {//最后一位是1
//			count++;
//		}
//		a /= 2;//移动到下一位
//	}
//	return count;
//
//}
//int main() {
//    int m = 1999;
//    int n = 2299;
//    int ret = m ^ n;
//    printf("%d\n", Numberof1(ret));
//    return 0;
//}

//4.获取一个数二进制的偶数位和奇数位
//int main() {
//    int a = 0;
//    scanf_s("%d", &a);
//    int i = 0;
//    printf("奇数位为:\n");
//    for (i = 0; i < 32; i = i + 2) {//奇数
//        printf("%d ", (a >> i) & 1);
//    }
//    printf("\n偶数位为:\n");
//    for (i = 1; i < 33; i = i + 2) {//偶数
//        printf("%d ", (a >> i) & 1);
//    }
//    return 0;
//}

//5.知识点
//①只要有了优先级和结合性，表达式就能求出唯一值（×）
//  (i++)+(i++)+(i++)这样的不同编译器都不一样，可以称为程序错误
//②局部指针变量不初始化就是野指针，野指针不能正常使用
//③int类型不管在32位机器还是64位机器下都是4个字节
  //指针在32位下是4个字节，64位下是8个字节
//④小端存储


//⑤十六进制的两位数字表示一个字节，八个bit位
//⑥C程序的基本组成单位是函数
//⑦C语言只是规定了语法规则，库函数实现什么的各个厂商都不一样
//⑧x和y都为double型，则执行x=2;y=x+3/2结果为：3.000000
//⑨*p++不是修改了指向的内容，而是修改了指针本身p++了





//6.
//int main() {
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;
//    int i = 0;
//    for (i = 0; i < 4; i++) {
//        *(p + i) = 0;
//    }
//    for (i = 0; i < 5; i++) {
//        printf("%d", arr[i]);
//    }
//
//    return 0;
//}

//7.以下程序的最终输出结果是：1
//#include<stdlib.h>
//int a = 1;//全局不优先，所以执行完a+=1以后就执行这句话
//void test() {
//    int a = 2;//局部优先，所以这句话优先
//    a += 1;
//}
//int main() {
//    test();
//    printf("%d\n", a);
//    return 0;
//}

//8.最大公约数还可以用辗转相除法
//  最小公倍数还可以用：设值整体代入法
//int main() {
//    int a = 0;
//    int b = 0;
//    scanf("%d%d", &a, &b);
//    int i = 1;
//    for (i = 1; ; i++) {
//        if (a * i % b == 0) {
//            printf("%d\n", a * i);
//            break;
//        }
//    }
//}

//9.输入一句英语,然后单词顺序逆序,标点还是在单词尾
//比如：I like beijing.->Beijing like I;
//主要思路是先整体逆序，然后每个单词负负得正逆序回来
void reverse(char* start, char* end) {
    while (start<=end) {
        char tmp = 0;
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}
int main() {
    char arr[100] = { 0 };
    //输入想要逆序的字符串
    gets_s(arr);//vs用gets_s
    unsigned int slen = strlen(arr);
    reverse(arr,arr+slen-1);//1.整体逆序
    //2.每个单词逆序
    char* start = arr;
    while (*start) {
        char* end = start;
        while(*end != ' '&& *end != '\0') {
            end++;
        }
        //开始逆序每一个单词
        reverse(start,end-1);
        if (*end == '\0') {
        start = end;//end指向最后了
        }
        else
           start = end + 1;
         
    }
    for (size_t i = 0; i < slen; i++) {
        printf("%c", arr[i]);
    }
    return 0;
}

