import java.util.*;
public class grade{
public static void main(String args[]){
int a=122;
if(a>=90 && a<=100)
     System.out.println("Grade O");
else if(a>=80 && a<=90)
     System.out.println("Grade E");
else if(a>=70 && a<=80)
     System.out.println("Grade A");
else if(a>=60 && a<=70)
     System.out.println("Grade B");
else if(a>=50 && a<=60)
     System.out.println("Grade C");
else if(a>=40 && a<=50)
     System.out.println("Grade D");
else if(a<40)
     System.out.println("Grade F");
else
     System.out.println("Incomplete");
}
}
