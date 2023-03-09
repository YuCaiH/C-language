#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//猜数字游戏，数字炸弹

void menu()//创建一个菜单
{
	printf("***********************\n");
	printf("*** 1.play  0.exit  ***\n");
	printf("***********************\n");
}

void game()
{
	int ret = 0;
	int guess = 0;//接收用户输入的猜的数字
	//1.生成随机数
	
	//time_t

	//srand((unsigned int)time(NULL));//函数放在这会导致生成的随机数很相近
	//这个随机数设置起点在一次运行中只需要一个起点，所以放在主函数中调用一次就ok
	//使用time函数要引入头文件time.h

	//在srand()里面输入的整型数据不同生成的随机数不同
	// 现在srand()里面需要一个在变动的数来作为随机数的生成起始点
	// 但是避免“套娃现象”，我们使用时间来作为随机数生成起始点，因为时间时刻在变化
	//时间戳：当前计算机的时间与计算机的起始时间（1970-01-01-00：00：00）相差的秒数
	//时间戳在不断变化

	ret=rand()%100+1;//rand()是用于生成随机数的函数
	//但是如果直接使用rand函数会发现程序两次运行生成的随机数是一样的
	// rand生成的是伪随机数，这就需要使用srand来解决这一问题了
	//printf("%d\n", ret);

	//rand生成随机数的范围是0到32767之间，如果我们要把范围控制在1到100之间
	//可以rand()%100+1 因为rand()%100的取值在0到99，+1之后就是1到100了

	//2.猜数字
	while (1)
	{
		printf("请猜猜数字： ");
		scanf_s("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		    menu();
			printf("请选择：");
			scanf_s("%d", &input);
			switch (input)
			{
			case 1:
				game();//game（）是游戏过程
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:  //如果用户输入的不是1或者0就用default来处理
				printf("选择错误");
				break;
			}
	}while (input);
	//如果输入0，那么循环结束，如果为非0，那么继续下一次游戏
	//也就是说，在想要继续游戏时或者选择错误时会再次进入菜单界面进行选择
	return 0;
}