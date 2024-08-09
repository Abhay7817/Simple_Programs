#include<stdio.h>
struct Product {
	char name[10];
	char id[10];
	int price;
};

int main() {
	int n;
	printf("Enter the number of products:");
	scanf("%d", &n);
	struct Product *p = (struct Product*)malloc(sizeof(struct Product)*n);
	for (int i = 0; i < n; i++) {
		printf("Enter details for product %d:", i + 1);
		printf("\nProduct Name:");
		scanf("%s", &(p+i)->name);
		printf("Product ID:");
		scanf("%s", &(p+i)->id);
		printf("Price:");
		scanf("%d", &(p+i)->price);
	}
	printf("Product Details:\n");
    for(int j = 0; j < n; j++) {
        printf("\tProduct Name: %s,\tProduct ID: %s,\tPrice: %d", (p+j)->name, (p+j)->id, (p+j)->price);
	}
	printf("\n\n");
	//the following two for loops works only with 5 products *improvement will be done
	for(int i=0; i<n; i++){
	 if(((p+i)->price) > ((p+1)->price) && ((p+i)->price) > ((p+2)->price) && ((p+i)->price) > ((p+3)->price) && ((p+i)->price) > ((p+4)->price)){
        printf("Most Expensive Product: %s,\tProduct ID: %s,\tPrice: %d",(p+i)->name,(p+i)->id,(p+i)->price);
	}
	}
	for(int i=0; i<n; i++){
	if(((p+i)->price) < ((p+1)->price) && ((p+i)->price) < ((p+2)->price) && ((p+i)->price) < ((p+3)->price) && ((p+i)->price) < ((p+4)->price)){
        printf("\nLeast Expensive Product: %s,\tProduct ID: %s,\tPrice: %d",(p+i)->name,(p+i)->id,(p+i)->price);
}
	}
	long int x=0;
	for(int i=0; i<n; i++){
	x = ((p+i)->price) + x;
	}
	printf("\nTotal Cost of All Products: %ld",x);
	return 0;
}
