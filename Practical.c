#include<stdio.h>
struct Friends{
    char name[20];
    char pet_name[10];
    long int phone_number;

    struct Type{
    char type_of_friend[10];
    char common_friends[50];
    int places_visited_together;
    };
};

int main(){
    int f;
    printf("Enter the number of friends to add: ");
    scanf("%d", &f);
    struct Friends f1[f];
      for(int i=0; i<f; i++){
        printf("Enter Friend Name: ");
        scanf("%s", &f1[i].name);
        printf("Enter Pet Name: ");
        scanf("%s", &f1[i].pet_name);
        printf("Enter Phone Number: ");
        scanf("%ld", &f1[i].phone_number);
        struct Type t;
        printf("Enter Type of Friend: ");
        scanf("%s", &t.type_of_friend);
        printf("Enter name of Common Friends: ");
        scanf("%s", &t.common_friends);
        printf("Enter No. of Places Visited Together: ");
        scanf("%d", &t.places_visited_together);
}
}

