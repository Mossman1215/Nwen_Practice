void fun1()
{

}
void fun2()
{

}
void fun3()
{

}
void (*func_ptr[3]) = {fun1, fun2, fun3};

main()
{
 int option;


    printf("\nEnter function number u want");
     printf("\nyou should not enter other than 0 , 1, 2"); /*bcos we hav only 3 functions*/
     scanf("%d",&option);

     if((option>=0)&&(option<=2))
       { 
         (*func_ptr[option])();
       }


   return 0;
}