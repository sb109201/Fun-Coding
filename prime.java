import java.util.*;
public class prime{
public static void main(String args[]){
 int a=13,i,c=0;
 for(i=2;i<13;i++){
 if(a%i==0)
 c++;
 }
 if(c==0){
   System.out.println("Prime");
 }
 else
     System.out.println("Grade O");
}
}
