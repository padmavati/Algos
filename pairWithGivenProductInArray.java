import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProductForPair {

    private  boolean productExistWithTwoElementsInArray(List<Integer> inputList, int product){

        List<Integer> temp = new ArrayList<>();

        for (Integer item : inputList) {

            if (product == 0 && item == 0)
                return true;
            if (item != 0 && product % item == 0) {
                if (temp.contains((product / item)))
                    return true;
                temp.add(item);
            }
        }
        return false;
    }
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        ProductForPair productForPair = new ProductForPair();

        int size = scanner.nextInt();

        List<Integer> arrayList = new ArrayList<Integer>();

        for(; size > 0; size--)
           arrayList.add(scanner.nextInt());

        int product = scanner.nextInt();

        System.out.print(productForPair.productExistWithTwoElementsInArray(arrayList, product));
    }
}
