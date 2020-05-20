#include <stdio.h>
int isEven(int num);
int main(){
	int n, i, max, min, mid, isInt;
	float midf;
	int data[1000];
	scanf("%d",&n);
	for(i = 0; i < n; i ++){
		scanf("%d", &data[i]);
	}
	//确定最大值和最小值
	if(data[n-1] >=data[0]){
		max = data[n - 1];
		min = data[0];
	}
	else{
		max = data[0];
		min = data[n-1];
	}
	//判断中位数是整数还是浮点数
	if((n/2)>(n-1)/2){
		//n是偶数
		isInt = isEven(data[n/2]+data[(n-1)/2]);
	}else{
		//n是奇数
		isInt = 1;
	}
	//计算中位数
	if(isInt==1){
		mid = (data[n/2] + data[(n - 1) / 2]) / 2;
		printf("%d %d %d",max, mid, min);	
	}
	else{
		midf = ((float)data[n/2] + (float)data[(n - 1) / 2]) / 2;
		printf("%d %.1f %d",max, midf, min);	
	}
	return 0;
}

int isEven(int num){
	return !(num&1);
}
