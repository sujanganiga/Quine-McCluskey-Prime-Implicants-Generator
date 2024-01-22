#include<iostream>
#include <bitset>
#include <algorithm>
using namespace std;
class quine{
       public:
            int static upd ; int static upd_pa ; int static upd_sp ;
            int up_date = 1 , first_dif , second_dif , third_dif , fourth_dif ;       
            int arr[ 16 ] , arr0[ 1 ] = { 16 } ;
            int arr1[ 16 ] , arr2[ 16 ] , arr3[ 16 ] , arr4[ 16 ] , arr5[ 16 ] ;
            int pair01[ 8 ][ 4 ][ 2 ] , pair12[ 8 ][ 4 ][ 2 ] , pair23[ 8 ][ 4 ][ 2 ] , pair34[ 8 ][ 4 ][ 2 ] , arrf[ 5 ][ 16 ][ 4 ] ;
            void decToBinary( int n , int num ) ; void stage2( int n ) ;
            void compare01( ) ; void compare12( ) ; void compare23( ) ; void compare34( ) ; void syscom1( ) ;
            void syscom2( int plair12[ 8 ][ 4 ][ 2 ] , int  plair23[ 8 ][ 4 ][ 2 ] , int k , int alrrch1[ 15 ] , int f1 , int inc ) ;
            void assign_o( ) ; void store_missing( int pair01[ 8 ][ 4 ][ 2 ] ) ;
            void missing_ele( ) ; void store_present( int a ) ;
            void missing_ele1( ) ;  void challenge( int n ) ;  void code_run( int a , int b ) ;
            int miss_arr[ 16 ] , presnt_arr[ 16 ] , presnt_arr1[ 16 ] , miss_arr1[ 16 ] ;
            void multi_syscom12( int p1air01[ 8 ][ 4 ][ 2 ] , int p1air12[ 8 ][ 4 ][ 2 ] ,int p1air23[ 8 ][ 4 ][ 2 ] , int k ) ;
            int varifing_arr[ 16 ][ 16 ] ;
            int prime_imp[ 5 ][ 8 ][ 8 ] ;
            void insert_pi( int n , int n1 , int num);
};
int  quine :: upd = 1 ;
int  quine :: upd_pa = 0 ;
int  quine :: upd_sp = 0 ;
void quine :: assign_o( ) {
    for ( int i = 0 ; i <= 8 ; i++ ) {
        for ( int j = 0 ; j <= 4 ; j++ ) {
            for( int k1 = 0 ; k1 <= 2 ; k1++ ) {
              pair01[ i ][ j ][ k1 ] = 16 ; pair12[ i ][ j ][ k1 ] = 16 ; pair23[ i ][ j ][ k1 ] = 16 ; pair34[ i ][ j ][ k1 ] = 16 ; 
            } } }
    for ( int i = 0 ; i < 16 ; i++ ) {
        miss_arr[ i ] = 16 ; miss_arr1[ i ] = 16 ; presnt_arr[ i ] = 16 ; presnt_arr1[ i ] = 16 ;
        arr1[ i ] = 16 ; arr2[ i ] =16 ; arr3[ i ] = 16 ; arr4[ i ] = 16 ; arr5[ i ] = 16 ; }
    for ( int i = 0 ; i < 16 ; i++ ){
        for( int j = 0 ; j < 16 ; j++ ){
                varifing_arr[ i ][ j ] = 16 ;
                 }  }
    for ( int i = 0 ; i < 5 ; i++ ) {
        for ( int j = 0 ; j < 8 ; j++ ) {
            for( int k1 = 0 ; k1 < 8 ; k1++ ) {
                prime_imp[ i ][ j ][ k1 ] = 16 ;
              } } }
}
int convert_into_pos(int a){
    if ( a == 1 ) { return 3 ; }
    else if ( a == 2 ) { return 2 ; } 
    else if ( a == 4 ) { return 1 ; } 
    else if ( a == 8 ) { return 0 ; }
    else if ( a == 0 ) { return -1 ; }
}
void  quine :: decToBinary ( int n , int num ){
    int binaryNum[ 4 ] = { 0 , 0 , 0 , 0 } , fake[ 4 ] = { 0 , 0 , 0 , 0 } , fake1[ 4 ] = { 0 , 0 , 0 , 0 } ;
    int pos1 , pos2 , pos3 , pos4 ; //cout<<"for decToBinary "<<n<<" binary is : ";
    int temp = n ; int i = 0;
    int asciiValue = 65;
    while ( n > 0 ) { 
        fake[ i ] = n % 2 ; 
        n = n / 2 ; 
        i++ ;    } 
    int k = 0 ;
    for ( int j = 3 ; j >= 0 ; j-- ) {
        binaryNum[ k ] = fake[ j ] ;
        k++ ;  }
    switch (num)
    {
        case 1 :
            for ( int i = 0 ; i <= 3 ; ++i ) {
                if ( binaryNum[ i ] == 1) {  fake1[i] = 2 ; }
                else{  fake1[ i ] = 0 ;  }       }
            break ;
        case 2 :
            break ;
        case 3 :
            pos1 = convert_into_pos( first_dif ) ;
            pos2 = convert_into_pos( second_dif ) ;
            for ( int j =3 ; j >= 0 ; j-- ) {
                if( pos1 == j ) {   binaryNum[ j ] = 2 ;  }
                if( pos2 == j ) {   binaryNum[ j ] = 2 ;  }   }
            break ;
        case 4 :
            pos3 = convert_into_pos( third_dif ) ;
            for ( int j = 3 ; j >= 0 ; j-- ) {
                if( pos3 == j ) {   binaryNum[ j ] = 2 ;  }   }
            break ;
        case 5 :
            pos4 = convert_into_pos( fourth_dif ) ;
            for ( int j = 3 ; j >= 0 ; j-- ) {
                if(binaryNum[ j ] == 1){  binaryNum[ j ] = 2 ;  }
                if ( pos4 == j )  {       binaryNum[ j ] = 1 ;  }  }
            break ;
        default:
            break ;
    }
    for ( int i = 0 ; i <= 3 ; ++i ) {
        if ( binaryNum[ i ] != 2 && fake1[ i ] != 2 ) {
            if( binaryNum[ i ] == 1 ) {
                char character = static_cast<char>( asciiValue +i ) ;
                cout << "\033[1;32m(" << character << ")\033[0m" ;  }
            else{
                char character = static_cast<char>( asciiValue +i ) ;
                cout << "\033[1;31m!(" << character << ")\033[0m" ; }
        }   }   
    cout << endl ;
} 
void quine :: insert_pi( int n , int n1 , int num ){
    for( int i =0; i <8 ; i++ ){
        if(prime_imp[ n ][ n1 ][ i ]==16){
           prime_imp[ n ][ n1 ][ i ]=num;
           break;
        }
    }
}
void quine :: stage2( int n ) {// cout<<"worked stage 2";
    if ( n==0 ) {
        arr0[ 0 ] = 0 ; presnt_arr[ 0 ] = 0 ;   }
    else if ( n == 1 || n == 2 || n == 4 || n == 8 ) {
        arr1[ n ] = n ; presnt_arr[ n ] = n ;   }
    else if ( n == 3 || n == 5 || n == 6 || n == 9 || n == 10 || n == 12 ) {
        arr2[ n ] = n ; presnt_arr[ n ] = n ;   }
    else if ( n == 7 || n == 11 || n == 13 || n == 14 ) {
        arr3[ n ] = n ; presnt_arr[ n ] = n ;   }
    else if ( n == 15 ) {
        arr4[ n ] = n ; presnt_arr[ n ] = n ;   }
}
bool search_in_s1( int arr[ ] , int num ) {
    bool count = 1 ;
    for( int i = 0 ; i < 15 ; i++ ){
        if( arr[ i ] == num ) {    return 0 ;    }
    }
    return count;
}
void quine :: store_missing ( int pair01[ 8 ][ 4 ][ 2 ] ) {
    for ( int i = 0 ; i <= 8 ; i++ ) {
        for ( int j = 0 ; j <=4 ; j++ ) {
            for ( int k1 = 0 ; k1 <= 2 ; k1++ ) {
                if ( pair01[ i ][ j ][ k1 ] >= 0 && pair01[ i ][ j ][ k1 ] < 16 ) {
                    if( search_in_s1( arr5 , pair01[ i ][ j ][ k1 ] ) ) {
                        arr5[ upd ] = pair01[ i ][ j ][ k1 ] ;
                        upd++;                    
                    }   }   }  }  }
}
void quine:: store_present ( int a ) {
    if ( search_in_s1( presnt_arr1,a ) ) {
        presnt_arr1[ upd_sp ] = a ;
        upd_sp++ ;  }
}
void quine::compare01(){
    int sub ; //cout<<"worked compare o1";
    if( arr0[ 0 ] == 0 ) {
        for ( int i = 1 ; i <= sizeof( arr1 ) / sizeof( arr1[0] ) ; ++i ) {
            if ( arr1[ i ] != 16 ) {   sub = arr1[ i ] - arr0[ 0 ] ; 
                    if ( sub == 1 )    {  
                        static int k1 = 0 ; pair01[ sub ][ k1 ][ 0 ] = arr0[ 0 ] ; pair01[ sub ][ k1 ][ 1 ] = arr1[ i ] ; k1++ ; }
                    else if( sub == 2 ){
                        static int k2 = 0 ; pair01[ sub ][ k2 ][ 0 ] = arr0[ 0 ] ; pair01[ sub ][ k2 ][ 1 ] = arr1[ i ] ; k2++ ; }    
                    else if( sub == 4 ){
                        static int k3 = 0 ; pair01[ sub ][ k3 ][ 0 ] = arr0[ 0 ] ; pair01[ sub ][ k3 ][ 1 ] = arr1[ i ] ; k3++ ; }  
                    else if( sub == 8 ){
                        static int k4 = 0 ; pair01[ sub ][ k4 ][ 0 ] = arr0[ 0 ] ; pair01[ sub ][ k4 ][ 1]  = arr1[ i ] ; k4++ ; }       
                       }  }   }
   store_missing( pair01 ) ; 
}
void quine::compare12(){
    int sub ;//cout<<"worked compare 12"<<endl;
    for ( int i = 1 ; i <= sizeof( arr1 ) / sizeof( arr1[ 0 ] ) ; ++i ) {
        if ( arr1[ i ] != 16 ) {
            for ( int j = 1 ; j <= sizeof( arr2 ) / sizeof( arr2[ 0] ) ; ++j ) {  
                if (arr2[j] != 16) {    sub = arr2[ j ] - arr1[ i ] ;
                    if ( sub == 1 )    {
                                static int k5 = 0 ; pair12[ sub ][ k5 ][ 0 ] = arr1[ i ] ; pair12[ sub ][ k5 ][ 1 ] = arr2[ j ] ; k5++ ; }
                    else if( sub == 2 ){
                                static int k6 = 0 ; pair12[ sub ][ k6 ][ 0 ] = arr1[ i ] ; pair12[ sub ][ k6 ][ 1 ] = arr2[ j ] ; k6++ ; }    
                    else if( sub == 4 ){
                                static int k7 = 0 ; pair12[ sub ][ k7 ][ 0 ] = arr1[ i ] ; pair12[ sub ][ k7 ][ 1 ] = arr2[ j ] ; k7++ ; }  
                            else if(sub==8){
                                static int k8 = 0 ; pair12[ sub ][ k8 ][ 0 ] = arr1[ i ] ; pair12[ sub ][ k8 ][ 1 ] = arr2[ j ] ; k8++ ; } 
                        }   }   }   }
    store_missing( pair12 ) ;
}
void quine::compare23(){
    int sub;//cout<<"worked compare 12"<<endl;
    for ( int i = 1 ; i <= sizeof( arr2 ) / sizeof( arr2[ 0 ] ) ; ++i ) {
        if ( arr2[ i ] != 16 ) {
            for (int j = 1 ; j <= sizeof( arr3 ) / sizeof( arr3[ 0 ] ) ; ++j ) {  
                if ( arr3[ j ] != 16 ) {   sub = arr3[ j ] - arr2[ i ] ;
                    if ( sub == 1 )    {
                                static int k5 = 0 ; pair23[ sub ][ k5 ][ 0 ] = arr2[ i ] ; pair23[ sub ][ k5 ][ 1 ] = arr3[ j ] ; k5++ ; }
                    else if( sub == 2 ){
                                static int k6 = 0 ; pair23[ sub ][ k6 ][ 0 ] = arr2[ i ] ; pair23[ sub ][ k6 ][ 1 ] = arr3[ j ] ; k6++ ; }    
                    else if( sub == 4 ){
                                static int k7 = 0 ; pair23[ sub ][ k7 ][ 0 ] = arr2[ i ] ; pair23[ sub ][ k7 ][ 1 ] = arr3[ j ] ; k7++ ; }  
                    else if( sub == 8 ){
                                static int k8 = 0 ; pair23[ sub ][ k8 ][ 0 ] = arr2[ i ] ; pair23[ sub ][ k8 ][ 1 ] = arr3[ j ] ; k8++ ; } 
                        }   }   }  }
    store_missing( pair23 ) ;
}
void quine::compare34(){
    int sub;// cout<<"worked compare 34"<<endl;
    for ( int i = 1; i <= sizeof( arr3 ) / sizeof ( arr3[ 0 ] ) ; ++i ) {
        if ( arr3[ i ] != 16 ) {
            for (int j = 1; j <= sizeof( arr4 ) / sizeof ( arr4[ 0 ] ); ++j ) {  
                if (arr4[j] != 16) {     sub = arr4[ j ] - arr3[ i ] ;
                    if ( sub == 1 )    {
                                static int k5 = 0 ;  pair34[ sub ][ k5 ][ 0 ] = arr3[ i ] ; pair34[ sub ][ k5 ][ 1 ] = arr4[ j ] ;  k5++ ; }
                    else if( sub == 2 ){ 
                                static int k6 = 0 ;  pair34[ sub ][ k6 ][ 0 ] = arr3[ i ] ; pair34[ sub ][ k6 ][ 1 ] = arr4[ j ] ;  k6++ ; }    
                    else if( sub == 4 ){
                                static int k7 = 0 ;  pair34[ sub ][ k7 ][ 0 ] = arr3[ i ] ; pair34[ sub ][ k7 ][ 1 ] = arr4[ j ] ;  k7++ ; }  
                    else if( sub == 8 ){
                                static int k8 = 0 ;  pair34[ sub ][ k8 ][ 0 ] = arr3[ i ] ; pair34[ sub ][ k8 ][ 1 ] = arr4[ j ] ;  k8++ ; } 
                        }   }   }   }
    store_missing( pair34 ) ;
}
int get_max( int a , int b , int c , int d , int e = -1 , int f = -1 , int g = -1 , int h = -1 ) {
    int maxVal = a;
    if ( b > maxVal ) {     maxVal = b;    }
    if ( c > maxVal ) {     maxVal = c;    }
    if ( d > maxVal ) {     maxVal = d;    }
    if ( e > maxVal ) {     maxVal = e;    }
    if ( f > maxVal ) {     maxVal = f;    }
    if ( g > maxVal ) {     maxVal = g;    }
    if ( h > maxVal ) {     maxVal = h;    }
    return maxVal;
}
int get_min( int a , int b , int c , int d , int e = 16 , int f = 16 , int g = 16 , int h = 16 ) {
    int minVal = a ;
    if ( b < minVal ) {     minVal = b ;    }
    if ( c < minVal ) {     minVal = c ;    }
    if ( d < minVal ) {     minVal = d ;    }
    if ( e < minVal ) {     minVal = e ;    }
    if ( f < minVal ) {     minVal = f ;    }
    if ( g < minVal ) {     minVal = g ;    }
    if ( h < minVal ) {     minVal = h ;    }
    return minVal;
}
bool find_16( int a , int b , int c , int d ) {
    if( a != 16 && b != 16 && c != 16 && d != 16 ) {  return 1; }
    else {  return 0; }
}
bool search_in_s3(int arr[],int num,int num1){
    bool count=1;
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
        if(arr[i]==num && arr[j]==num){
            return 0;
        }
        }
    }
    return count;

}
void quine::syscom1(){
    int numd , num; //cout<<"worked compare 1jk"<<endl;
    static int f = 0 ; static int k = 1 ; static int inc = 0 ; 
    static int arrch[ 15 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0 , 0 } ;
    for( int i = 0 ; i < 3 ; i++ ) {
          for( int j = 0 ; j < 3 ; j++ ) {
                num  =  get_max( pair01[ k ][ i ][ 0 ] , pair01[ k ][ i ][ 1 ] , pair12[ k ][ j ][ 1 ] , pair12[ k ][ j ][ 0 ] ) ;
                if( num > 0 && num <= 15 && find_16( pair01[ k ][ i ][ 0 ] , pair01[ k ][ i ][ 1 ] , pair12[ k ][ j ][ 1 ] , pair12[ k ][ j ][ 0 ] ) ) {
                    if ( search_in_s1( arrch , num ) ) {
                        cout<<"\033[1;33m("<<pair01[ k ][ i ][ 0 ] <<","<< pair01[ k ][ i ][ 1 ] <<")"<<"("<< pair12[ k ][ j ][ 0 ] <<","<< pair12[ k ][ j ][ 1 ]<<")\033[0m"<<"\033[1;35m   -->   \033[0m ";
                        store_present ( pair01 [ k ][ i ][ 0 ] ) ; store_present( pair01[ k ][ i ][ 1 ] ) ; store_present( pair12[ k ][ j ][ 0 ] ) ; store_present( pair12[ k ][ j ][ 1 ] ) ;
                        insert_pi ( 1 , inc , pair01 [ k ][ i ][ 0 ] ) ; insert_pi( 1 , inc ,  pair01[ k ][ i ][ 1 ] ) ;
                        insert_pi( 1 ,  inc , pair12[ k ][ j ][ 0 ] ) ; insert_pi ( 1 , inc ,  pair12[ k ][ j ][ 1 ] ) ;
                        inc++;
                        arrch[ f ] = num ;  f++ ;
                        decToBinary( num, 1 ) ;    }   }
               if( i == 2 && j == 2 ) {
                k++;
                if(k <=8) {  syscom1() ; }
                else {  break; }  }
                }   }
}
void quine::syscom2 (int plair12[8][4][2],int plair23[8][4][2], int k, int alrrch1[15],int f1 , int inc ){
    int num , num1 , num2 , num5 ;
    for( int i = 0 ; i < 3 ; i++ ) {
          for( int j = 0 ; j < 3 ; j++ ){
                num = get_min ( plair12[k][i][1] , plair12[k][i][0] , plair23[k][j][1] , plair23[k][j][0] ) ;
                num5 = get_max ( plair12[k][i][1] , plair12[k][i][0] , plair23[k][j][1] , plair23[k][j][0] ) ;

                num1 = plair23[k][j][0] - plair12[k][i][0] ; num2 = plair23[k][j][1] - plair12[k][i][0] ;
                if( num > 0 && num <= 15 &&( num1 == 1 || num1 == 2 || num1==4 || num1==8 ) && find_16( plair12[k][i][1] , plair12[k][i][0] , plair23[k][j][1] , plair23[k][j][0] ) ) {                
                   if(search_in_s1( alrrch1 ,num5) ){
                       cout<<"\033[1;33m("<<pair12[ k ][ i ][ 0 ] <<","<< pair12[ k ][ i ][ 1 ] <<")"<<"("<< pair23[ k ][ j ][ 0 ] <<","<< pair23[ k ][ j ][ 1 ]<<")\033[0m"<<"\033[1;35m   -->   \033[0m ";
                      store_present( plair12[k][i][0] ) ; store_present( plair12[k][i][1] ) ; store_present( plair23[k][j][0] ) ;store_present( plair23[k][j][1] ) ;
                       insert_pi ( 2 , inc , plair12 [ k ][ i ][ 0 ] ) ; insert_pi( 2 , inc ,  plair12[ k ][ i ][ 1 ] ) ;
                      insert_pi( 2 ,  inc , plair23[ k ][ j ][ 0 ] ) ; insert_pi ( 2 , inc ,  plair23[ k ][ j ][ 1 ] ) ;
                      inc++;
                      alrrch1[f1] = num5 ; f1++;
                      //alrrch1[f1] = num ; f1++ ;
                      first_dif = k ; second_dif = num1 ;
                      decToBinary( num , 3 ) ;   }  }
                if( i == 2 && j == 2 ) {
                k++ ;
                if ( k <= 8 ) {    syscom2( plair12 , plair23 , k , alrrch1 , f1 , inc );  }                
                else {  break; }       }
                                   }   }
}
void  quine :: multi_syscom12 (int p1air01[ 8 ][ 4 ][ 2 ] , int p1air12[ 8 ][ 4 ][ 2 ] , int p1air23[ 8 ][ 4 ][ 2 ] , int k ) {
    int max , min , n1 , n2 , n3 , n4 , n5 ;   
    for ( int i = 0 ; i < 3 ; i++ ) {
        for ( int j = 0 ; j < 3 ; j++ ) {
            for ( int l = 0 ; l < 3 ; l++ ) {
                for ( int m = 0 ; m < 3 ; m++ ) {
                    int  a , b , c , d , e , f , g , h ;
                    a = p1air01[ k ][ i ][ 0 ] ; b = p1air01[ k ][ i ][ 1 ] ; c = p1air12[ k ][ j ][ 0 ] ; d = p1air12[ k ][ j ][ 1 ] ;
                    e = p1air12[ k ][ l ][ 0 ] ; f = p1air12[ k ][ l ][ 1 ] ; g = p1air23[ k ][ m ][ 0 ] ; h = p1air23[ k ][ m ][ 1 ] ;
                    max = get_max ( a , b , c , d , e , f , g , h ) ;
                    min = get_min( a , b , c , d , e , f , g , h ) ;
                    n1 = d - b ; n2 = b - e ; n3 = b - g ; n4 = g - e ; n5 = e - c ;
                    if ( max > 0 && max <= 15 && ( n1 == 1 || n1 == 2 || n1 == 4 || n1 == 8 ) && ( n5 == 1 || n5 == 2 || n5 == 4 || n5 == 8 ) && ( n4 == 1 || n4==2 || n4==4 || n4==8 ) && find_16( a , b , c , d ) && find_16( e, f, g, h)){
                        if( max <= 15 && max != -1 && ( min == 0 || min == 1 || min == 2 || min == 4 || min==8 ) && varifing_arr[max][min] == 16 ){
                            fourth_dif = min ;
                            cout<<"\033[1;33m("<<a<<","<<b<<","<<c<<","<<d <<")("<< e <<","<< f <<","<< g <<","<< h <<")\033[0m"<<"\033[1;35m   -->   \033[0m ";
                            varifing_arr[ max ][ min ] = 1;
                            decToBinary( max , 5 ) ; }  }
                    if ( i == 2 && j == 2 && l == 2 && m == 2 ){  k++;
                            if( k <= 8 ) { multi_syscom12(p1air01 , p1air12 , p1air23 , k );  }
                            else { break ; }
                                }   }   }   }   }
}
void  quine  ::  missing_ele( ) {
    int m ;int k=1 ; // cout<<"worked ele first"<<endl;
    for ( int i = 0 ; i <= 15 ; i++ ){    m = 16;      
        for ( int j = 0 ; j <= 15 ; j++ ){
            if ( presnt_arr[ i ] == 0 && arr5[ j ] == 0 ){ m = i ; k = 0 ; break ; }
            if ( presnt_arr[ i ] == arr5[ j ] && presnt_arr[ i ] < 16 && arr5[ j ] < 16 ) {  m = i ; k = 0 ; break ; }  
        }
        if ( k == 1 && presnt_arr[ i ] < 16 && m != i ){
            miss_arr[ up_date ] = presnt_arr[ i ] ;
            up_date++ ;
            //insert_pi ( 1 , inc , plair12 [ k ][ i ][ 0 ] )
            cout<<"\033[1;33m("<<presnt_arr[ i ]<<")\033[0m"<<"\033[1;35m   -->   \033[0m ";
            decToBinary( presnt_arr[ i ] , 2 ) ; }
      }
}
void quine::missing_ele1( ){
    int m ; //cout<<"worked ele1"<<endl;
    for ( int i = 0  ; i < 15 ; i++ ) {  int k = 1 ;
        for ( int j = 0 ; j < 15 ; j++ ) {
            if ( arr5[ i ] == 0 && presnt_arr1[ j ] == 0 ){
                m = i ; k = 0 ; break ; }
            else if ( presnt_arr1[ j ] == arr5[ i ] && presnt_arr1[ j ] < 16 && arr5[ i ] < 16 ) {
                m = i ; k = 0 ; break ;  }   }
        if( k == 1 && arr5[ i ] < 16 && m != i){
            challenge( arr5[ i ] ) ; }    }
}
int absolute( int a , int b ) {
    int difference = a - b;
    return (difference < 0) ? -difference : difference;
}
void quine :: code_run( int a , int b ) {
    third_dif = absolute( a , b ) ;
    int num ;
    if ( a > b ) { num = b ; }
    else { num = a ; }
    if ( (third_dif == 1 || third_dif == 2 || third_dif == 4 || third_dif == 8) && search_in_s1 ( miss_arr1 , num )) {
     miss_arr1[ up_date ] = num ;
     up_date++ ;
    cout<<"\033[1;33m("<<a<<","<<b <<")\033[0m"<<"\033[1;35m   -->   \033[0m ";
    decToBinary( num , 4) ;  }
}
void quine :: challenge( int n ) {
    // cout<<"taking element"<<n<<endl;
    if ( n== 15 ) {
        for ( int i = 0 ; i < 16 ; i++ ) {
             if ( arr3[ i ] < 16 ) {
                code_run( n , arr3[ i ] ) ;  }  }  }
    else if ( n == 14 || n == 13 || n == 11 || n == 7 ) {
        for ( int i = 0 ; i < 16 ; i++ ) {
            if ( arr2[ i ] < 16 ) {
                code_run( n , arr2[ i ] ) ; }
            if ( arr4[ i ] < 16 ) {
                code_run( n , arr4[ i ] ) ; }  }  }
    else if ( n == 3 || n == 5 || n == 6 || n == 9 || n == 10 || n == 12 ) {
         for( int i = 0 ; i < 16 ; i++ ){
            if ( arr1[ i ] < 16 ){
                code_run( n , arr1[ i ] ) ; }
            if( arr3[ i ] < 16 ){
                code_run( n , arr3[ i ] ) ; } } }
    else if ( n == 1 || n == 2 || n == 4 || n == 8 ) {
        for ( int i = 0 ; i < 16 ; i++ ){
            if ( arr0 [ i ] < 16 ){
                code_run( n , arr0[ i ] ) ;  }
            if ( arr2[ i ] < 16 ){
                code_run( n , arr2[ i ] ) ;  } } }
    else if ( n == 0 ){
        for ( int i = 0 ; i < 16 ; i++ ){
            if ( arr1 [ i ] < 16 ) {
            code_run( arr1[ i ] , n ) ; } } }
}
int main(){ 
    quine a1;
    a1.assign_o();
    cout<< endl << "\033[1;31mINSTUCTIONS : DONT ENTER INPUT WHICH FORMS OCTAL IN K-MAP \033[0m" << endl;
    cout<< endl << "enter the total number of inputs  :"<<endl;
    int n ; cin>> n;
    for(int i=0;i<n;i++){
        int n1;
        cout<<"enter the inputs  : ";
        cin>>n1;
        a1.stage2(n1);}
    cout << endl << "\033[1;34mPRIME IMPLICANTS ARE :\033[0m" << endl <<endl;
    a1.compare01();a1.compare12();a1.compare23();a1.compare34();
    static int k3 = 1 ; static int k4 = 1 ; static int f1 = 0 ; static int f2 = 0 ;static int inc1 = 0 ; static int inc2 = 0 ;
    static int arrch1 [ 15 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0 , 0 ,0 , 0 } ;  static int arrch2[ 15 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0 , 0 ,0 , 0 } ;
   a1.syscom1() ; a1.syscom2( a1.pair12 , a1.pair23 , k3 , arrch1 , f1 ,inc1 ) ;  a1.syscom2( a1.pair23 , a1.pair34 , k3 , arrch2 , f2 ,inc2 ) ;
   a1.missing_ele( ) ; a1.missing_ele1( ) ;
   static int k2=1;  static int k1=1;
   a1.multi_syscom12( a1.pair01 , a1.pair12 , a1.pair23 , k1 ) ;  a1.multi_syscom12( a1.pair12 , a1.pair23 , a1.pair34 , k2 ) ; cout<<endl<<endl;   
   return 0; 
} 
/*MIT License

Copyright (c) [2024] [SUJAN GANIGA] [Quine-McCluskey-Prime-Implicants-Generator]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
