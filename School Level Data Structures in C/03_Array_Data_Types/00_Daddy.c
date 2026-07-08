#include <stdio.h>

int main(){

    int arr[100];
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    do{

        printf("\n------ MENU ------\n");
        printf("1.Display\n");
        printf("2.Sum(Add)\n");
        printf("3.Append\n");
        printf("4.Insert\n");
        printf("5.Delete\n");
        printf("6.Search\n");
        printf("7.Get Index Value\n");
        printf("8.Set Index Value\n");
        printf("9.Maximum\n");
        printf("10.Minimum\n");
        printf("11.Reverse\n");
        printf("12.Shift Left\n");
        printf("13.Rotate Left\n");
        printf("14.Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){

        case 1:{
            printf("Array: ");
            for(int i=0;i<n;i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
        }

        case 2:{
            int sum=0;

            for(int i=0;i<n;i++){
                sum += arr[i];
            }

            printf("Sum = %d\n",sum);
            break;
        }

        case 3:{
            int value;

            printf("Enter value to append: ");
            scanf("%d",&value);

            arr[n]=value;
            n++;

            break;
        }

        case 4:{
            int index,value;

            printf("Enter index: ");
            scanf("%d",&index);

            printf("Enter value: ");
            scanf("%d",&value);

            for(int i=n;i>index;i--){
                arr[i]=arr[i-1];
            }

            arr[index]=value;
            n++;

            break;
        }

        case 5:{
            int index;

            printf("Enter index to delete: ");
            scanf("%d",&index);

            for(int i=index;i<n-1;i++){
                arr[i]=arr[i+1];
            }

            n--;

            break;
        }

        case 6:{
            int key,found=0;

            printf("Enter element to search: ");
            scanf("%d",&key);

            for(int i=0;i<n;i++){

                if(arr[i]==key){
                    printf("Found at index %d\n",i);
                    found=1;
                    break;
                }
            }

            if(found==0){
                printf("Not Found\n");
            }

            break;
        }

        case 7:{
            int index;

            printf("Enter index: ");
            scanf("%d",&index);

            printf("Value = %d\n",arr[index]);

            break;
        }

        case 8:{
            int index,value;

            printf("Enter index: ");
            scanf("%d",&index);

            printf("Enter new value: ");
            scanf("%d",&value);

            arr[index]=value;

            break;
        }

        case 9:{
            int max=arr[0];

            for(int i=1;i<n;i++){

                if(arr[i]>max){
                    max=arr[i];
                }
            }

            printf("Maximum = %d\n",max);

            break;
        }

        case 10:{
            int min=arr[0];

            for(int i=1;i<n;i++){

                if(arr[i]<min){
                    min=arr[i];
                }
            }

            printf("Minimum = %d\n",min);

            break;
        }

        case 11:{
            int temp;

            for(int i=0;i<n/2;i++){

                temp=arr[i];
                arr[i]=arr[n-1-i];
                arr[n-1-i]=temp;
            }

            printf("Array Reversed\n");

            break;
        }

        case 12:{

            for(int i=0;i<n-1;i++){
                arr[i]=arr[i+1];
            }

            arr[n-1]=0;

            printf("Left Shift Done\n");

            break;
        }

        case 13:{
            int temp=arr[0];

            for(int i=0;i<n-1;i++){
                arr[i]=arr[i+1];
            }

            arr[n-1]=temp;

            printf("Left Rotate Done\n");

            break;
        }

        case 14:
            printf("Program Ended\n");
            break;

        default:
            printf("Invalid Choice\n");

        }

    }while(choice!=14);

    return 0;
}