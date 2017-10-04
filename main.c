#include "Include_and_constants.h"
#include <windef.h>



struct ItemsInBackpack
{
    int Price;
    int Weight;
    int InBackPack;
};




int Backpack()
{

    system("cls");
    printf("Set amount of items_ \n");
    int     AmountOfItems = In() ,
            TotalPriceRightNow = 0 ,
            WeightAtThisPoint = 0 ,
            TotalPrice = 0 ,
            *RightNowInBackpack = (int*)malloc( ( AmountOfItems + 1 ) * sizeof( int ) );
    struct  ItemsInBackpack *ThisTime = (struct ItemsInBackpack*)malloc( ( AmountOfItems + 1 ) * sizeof( struct ItemsInBackpack ) );
    for( int i = 0 ; i < AmountOfItems ; i++ )
    {
        printf("Set price of %d item_ \n" , i + 1 );
        ThisTime[i].Price = In();
        printf("Set weight of %d item_ \n" , i + 1 );
        ThisTime[i].Weight = In();
        ThisTime[i].InBackPack = 0;
    }
    printf("Set size of backpack_ \n");
    int  SizeOfBackpack = In();
    for( int i = 0 ; i < AmountOfItems ; i++)
    {
        for( int k = 0 ; k < AmountOfItems ; k++ )RightNowInBackpack[ k ] = 0 ;
        WeightAtThisPoint = 0 ;
        TotalPriceRightNow = 0 ;
        for( int j = i ; j < AmountOfItems ; j++ )
        {
            if( ( WeightAtThisPoint <= SizeOfBackpack ) && ( ( WeightAtThisPoint + ThisTime[ j ].Weight ) <= SizeOfBackpack) )
            {
                WeightAtThisPoint = WeightAtThisPoint + ThisTime[ j ].Weight;
                TotalPriceRightNow = TotalPriceRightNow + ThisTime[ j ].Price;
                RightNowInBackpack[ j ] = 1;
            }
            if ( TotalPriceRightNow > TotalPrice )
                {
                    TotalPrice = TotalPriceRightNow ;
                    for(int k = 0 ; k < AmountOfItems ; k++)ThisTime[ k ].InBackPack = RightNowInBackpack[ k ];
                }

        }

    }
    for( int i = 0 ; i < AmountOfItems ; i++ ) if( ThisTime[ i ].InBackPack == 1 )printf("%d-th is in backpack\n" , i + 1);
    printf("Total price is %d\n" , TotalPrice);
}




int main()
{
   while(TRUE)
   {
      system("cls");
       printf("1.Find optimal variant of backpack configuration\n2.Exit\n");
       char Choose = getch();
       switch(Choose)
       {
           case '1' :
               Backpack();
               printf("Press any button to restart the programme_");
               getch();
               break;
           case '2' :
               return 0;
       }
   }

}