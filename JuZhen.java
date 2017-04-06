import java.util.*;

public class JuZhen{

    private int hang;
    private int lie;
    private int[][] juzhen;

    public JuZhen(int hang, int lie){

        this.hang = hang;
        this.lie = lie;

        this.juzhen = new int[hang][lie];

    }

    public void setin(){

        System.out.println("请输入矩阵元素:");
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<this.hang; i++){
            for(int j=0; j<this.lie; j++){
                this.juzhen[i][j] = sc.nextInt();
            }
        }

    }

    public int gethang() {

        return hang;

    }

    public int getlie() {

        return lie;

    }

    public JuZhen XiangCheng(JuZhen juzhen){

        JuZhen xiangchenghou = new JuZhen(this.gethang(), juzhen.getlie());

        for (int i=0; i<this.gethang(); i++){
            for (int j=0; j<juzhen.getlie(); j++){
                int sum = 0;
                for (int k=0; k<juzhen.gethang(); k++){
                    sum += this.juzhen[i][k] * juzhen.juzhen[k][j];
                }
                xiangchenghou.juzhen[i][j] = sum;
            }
        }

        return xiangchenghou;

    }

    public void display(){
        for(int[] i : this.juzhen){
            for(int j : i){
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        System.out.print("请输入矩阵1的行、列: ");
        int hang = sc.nextInt();
        int lie = sc.nextInt();
        juzhen juzhen1 = new juzhen(hang,lie);
        juzhen1.setin();

        System.out.print("请输入矩阵2的行、列: ");
        hang = sc.nextInt();
        lie = sc.nextInt();
        juzhen juzhen2 = new juzhen(hang,lie);
        juzhen2.setin();

        juzhen xiangchenghou = juzhen1.xiangcheng(juzhen2);
        System.out.println("矩阵相乘后:");
        xiangchenghou.display();

    }

}
