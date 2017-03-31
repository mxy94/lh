import java.util.*;

public class FamilyMember{
    public string xing;
    private string ming;
    static string familyxing;

    FamilyMember(string xing,string ming)
    {
        this.xing=xing;
        this.ming=ming;
    }
    public static void main(String args[]){
       System.out.println("请输入家族姓：")；
       Scanner reader=new Scanner(System.in);
       FamilyMember.familyxing=reader.nextLine();
       int sum=0;
       System.out.println("请输入人员个数：")；
       int n=reader.nextInt();
       for(int j=0;j<n;j++)
       {
           System.out.println("请输入成员"+(j+1)+"的姓名");
           FamilyMember m=new FamilyMember(reader.nextLine(),reader.nextLine());
           if(m.xing==FamilyMember.familyxing)
           {
               sum++;
           }
       }
       System.out.println("该家族共有"+sum+"个成员");
    }

}
