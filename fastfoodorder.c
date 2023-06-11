#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdbool.h>



struct MenuItem 
{
   char code[100];
   char items;
     

};

void showmenu();

//Global Array
  int itemQuantity[4] = { 0,0,0,0 };
 float itemPrice[4] = { 4.59, 1.05, 4.59, 2.49 };



int main()
{
 showmenu();
return 0;
}


 

//function for input ouput and process
void showmenu(){

    int quantityCount;
    float price;
    float totalPrice;
    char choices;
    
    bool menuLoop, quantityLoop;
    bool choiceLoop = true, validateLoop = true;

    struct MenuItem menu;

    // quantity = EnterFunc(new.quantity);
    do
    {
    	menuLoop = true;
    	quantityLoop = true;
        do
        {
            printf("Enter the Item Code[M1,M2,M3,M4]: ");
            scanf("%s", menu.code);

            if ((strcmp(menu.code, "M1") == 1) && (strcmp(menu.code, "M2") == 1) && (strcmp(menu.code, "M3") == 1) && (strcmp(menu.code, "M4") == 1))
            {
                printf("Invalid Input! Please Try Again!\n\n");
            }
            else
            {
                menuLoop = false;
            }
        } while (menuLoop);

        do
        {
            printf("Enter Quantity: ");
            scanf("%d", &quantityCount);

            if (quantityCount < 1)
            {
                printf("Invalid Input! Value cannot less than 0!\n\n");
            }
            else
            {
                quantityLoop = false;
            }
        } while (quantityLoop);

        if (strcmp(menu.code, "M1") == 0) {
            itemQuantity[0] += quantityCount;
        }
        else if (strcmp(menu.code, "M2") == 0) {
            itemQuantity[1] += quantityCount;
        }
        else if (strcmp(menu.code, "M3") == 0) {
            itemQuantity[2] += quantityCount;
        }
        else if (strcmp(menu.code, "M4") == 0) {
            itemQuantity[3] += quantityCount;
        }

		fflush(stdin);
        do
        {
            printf("Do you want to make another order Y/N: ");
            scanf("%c", &choices);

            if (choices == 'Y' || choices == 'y')
            {
                printf("\n");
                validateLoop = false;
            }
            else if (choices == 'N' || choices == 'n')
            {
                printf("\n");
                choiceLoop = false;
                validateLoop = false;
            }
            else
            {
                printf("Invalid Input! Please Try Again!\n\n");
            }
        } while (validateLoop);

    } while (choiceLoop);

    totalPrice =  (itemQuantity[0] * itemPrice[0]) + (itemQuantity[1] * itemPrice[1]) + (itemQuantity[2] * itemPrice[2]) + (itemQuantity[3] * itemPrice[3]);

    printf("\nMenu item           Quantity");
    printf("\n----------------------------");
    printf("\nChicken Burger         %d", itemQuantity[0]);
    printf("\nRainbow Fillet         %d", itemQuantity[1]);
    printf("\nNo SaltFries           %d", itemQuantity[2]);
    printf("\nSoft Drink             %d", itemQuantity[3]);
    printf("\nTotal Price  :RM %.2f", totalPrice);

}