public class MyClass {
    public static void main(String args[]) {
      if (args.length == 3) {
        if (Integer.parseInt(args[0]) == Integer.parseInt(args[1]) && Integer.parseInt(args[0]) == Integer.parseInt(args[2])) {
          System.out.println("equal");
          return;
        }
      }
      System.out.println("not equal");
    }
}
