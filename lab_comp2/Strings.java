package lab_comp2;
import java.util.*;

public class Strings {
    public static void main(String[] args) {
      Scanner sc=new Scanner(System.in);
      System.out.println("Coloque a primeira string");
      String string1=sc.nextLine();
      System.out.println("Coloque a segunda string");
      String string2=sc.nextLine();
      char[] xdd1=string1.toCharArray();
      char[] xdd2=string2.toCharArray();
      int x=0;

      for(int i=0;i<xdd1.length;i++){
        int k=0;
        for(int j=0;j<xdd2.length;j++){
          if(i+j >= xdd1.length){
            break;
          }
          if(xdd1[i+j]==xdd2[j]){
            k++;
          }
        }
        if(k==xdd2.length){
          x++;
        }
      }
      System.out.println("Tiveram " + x +" repeticoes");
      sc.close();
    }
  }