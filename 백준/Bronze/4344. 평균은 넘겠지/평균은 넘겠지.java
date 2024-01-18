import java.util.*;

class Main {
  Scanner sc = new Scanner(System.in);
  List<Integer>[] arr;
  
  public static void main(String[] args) {
    Main ct = new Main();
    ct.body();
  }

  void body(){
    int cnt = sc.nextInt();
    arr = new ArrayList[cnt];
    for(int i=0;i<cnt;i++){
      arr[i] = new ArrayList<Integer>();
    }
    
    for(int i=0;i<cnt;i++){
      int students = sc.nextInt();
      for(int j=0;j<students;j++){
        int jumsu = sc.nextInt();
        arr[i].add(jumsu);
      }
    }

    int sum[] = new int[cnt];
    double avg[] = new double[cnt];
    
    for(int i=0;i<cnt;i++){
      for(int j=0;j<arr[i].size();j++){
        sum[i] += arr[i].get(j);
      }
      avg[i] = (double)sum[i]/arr[i].size();
    }
    
    for(int i=0;i<cnt;i++){
      int overCnt = 0;
      for(int j=0;j<arr[i].size();j++){
        if(arr[i].get(j)>avg[i]) overCnt++;
      }
      double per = (double)overCnt/arr[i].size()*100;
      System.out.println(String.format("%.3f",per)+"%");
    }
    
  }
}