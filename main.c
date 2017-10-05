#include "Include_and_constants.h"
#include <windef.h>



struct ItemsInBackpack //определяем структуру для более удобного доступа к данным
{
    int Price ;
    int Weight ;
    int InBackPack ;
} ;




int Backpack()
{

    system( "cls" ) ;
    printf( "Set amount of items_ \n" ) ;
    int     AmountOfItems = In() , //читаем общее количество вещей
            TotalPriceRightNow = 0 , //максимальная цена в этом случае перебора
            WeightAtThisPoint = 0 , //вес в этом случае перебора
            TotalPrice = 0 , //конечная максимальная цена
            *RightNowInBackpack = ( int* )malloc( ( AmountOfItems + 1 ) * sizeof( int ) ) ; // выделяем место под массив для флагов во время полного перебора
    struct  ItemsInBackpack *ThisTime = ( struct ItemsInBackpack* )malloc( ( AmountOfItems + 1 ) * sizeof( struct ItemsInBackpack ) ) ; //выделяем место под массив из нашей структуры
    for( int i = 0 ; i < AmountOfItems ; i ++ ) //читаем все данный о каждом предмете и записываем в структуру
    {
        printf( "Set price of %d item_ \n" , i + 1 ) ;
        ThisTime[i].Price = In() ; //читаем цену
        printf( "Set weight of %d item_ \n" , i + 1 ) ;
        ThisTime[i].Weight = In() ; //читаем вес
        ThisTime[i].InBackPack = 0 ; //обнуляем флаги
    }
    printf( "Set size of backpack_ \n" ) ;
    int  SizeOfBackpack = In() ; //читаем максимальную грузоподЪемность
    for( int i = 0 ; i < AmountOfItems ; i ++ ) //начинаем полный перебор
    {
        for( int k = 0 ; k < AmountOfItems ; k ++ ) RightNowInBackpack[ k ] = 0 ; //обнуляем всременные флаги кажждый раз
        WeightAtThisPoint = 0 ; //обнуляем вес в этом переборе
        TotalPriceRightNow = 0 ; //обнуляем общюю цену в данном переборе
        for( int j = i ; j < AmountOfItems ; j ++ ) //осуществляем перебор
        {
            if( ( WeightAtThisPoint <= SizeOfBackpack ) && ( ( WeightAtThisPoint + ThisTime[ j ].Weight ) <= SizeOfBackpack ) ) //если объект выполняет условия веса и мы еще не превысили лимит то
            {
                WeightAtThisPoint = WeightAtThisPoint + ThisTime[ j ].Weight ; //увеличиваем вес
                TotalPriceRightNow = TotalPriceRightNow + ThisTime[ j ].Price ; //увеличиваем полную цену
                RightNowInBackpack[ j ] = 1 ; //меняем временный флаг
            }
            if ( TotalPriceRightNow > TotalPrice ) //если цена полученная в почледнем выполенном переборе больше всех полученных до этого то
                {
                    TotalPrice = TotalPriceRightNow ; //увеличиваем макс цену
                    for( int k = 0 ; k < AmountOfItems ; k ++ ) ThisTime[ k ].InBackPack = RightNowInBackpack[ k ] ; // переносим временных флагов в основной
                }

        }

    }
    for( int i = 0 ; i < AmountOfItems ; i ++ ) if( ThisTime[ i ].InBackPack == 1 ) printf( "%d-th is in backpack\n" , i + 1 ) ;
    printf( "Total price is %d\n" , TotalPrice) ;
}




int main() //меню
{
   while(TRUE)
   {
      system( "cls" ) ;
       printf( "1.Find optimal variant of backpack configuration\n2.Exit\n" ) ;
       char Choose = getch() ;
       switch( Choose )
       {
           case '1' :
               Backpack() ;
               printf( "Press any button to restart the programme_" ) ;
               getch() ;
               break ;
           case '2' :
               return 0 ;
       }
   }

}