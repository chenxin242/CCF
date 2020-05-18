代码：
#include<stdio.h>
int main() {
	int t=0;
	int L=0;
	int n=0;
//	printf("请输入n、L、t:\n");
	scanf("%d %d %d",&n,&L,&t);
	//利用数据结构
	struct Node {
		int location;              // 位置
		int towards;              // 运动方向，1表示向右，-1表示向左
	} a[n+1];				         //可以不填吗？
	//输入数据
//	printf("请输入小球的位置:\n");
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i].location);
		a[i].towards = 1;
	}
	//判断：
	for(int i=1; i<=t; i++) {          						 //秒数
		for(int j=1; j<=n; j++) {      						 //小球
			//检测是否有碰撞
			for(int k=1; k<=n; k++) {
				if(j!=k) {
					if(a[j].location==a[k].location) {	  //发生碰撞
						a[j].towards =-a[j].towards;      //-1，1不足以控制，应该设置为相反数，要考虑两个端点
						a[k].towards =-a[k].towards;
						break;
					}
				}
			}
			//碰撞检测确定方向后开始计算位置。
			if(a[j].location ==L) {
				a[j].location-=1;
				a[j].towards = -1;                        //这里不是相反数 ，直接是 -1
			} else if((a[j].towards ==-1&&a[j].location ==0)||(a[j].towards ==1&&a[j].location ==0)) {
				a[j].location+=1;
				a[j].towards = 1;  						 //这里不是相反数
			} else if(a[j].towards ==-1) {
				a[j].location -=1;            			 //采用一步一步走
			} else {
				a[j].location+=1;
			}
		}
		/*
		printf("第%d秒的位置   :   ",i);
		for(int s=1; s<=n; s++) {
			printf("%d ",a[s].location);
		}
		printf("\n");
		*/
	}
//	printf("最终各个小球的位置如下：\n");
	for(int i=1; i<=n; i++) {
		printf("%d ",a[i].location);
	}
	return 0;
}
