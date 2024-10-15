import java.util.Scanner;

public class Main{
	public static int partition(int[] arr, int l, int r){
		int pivot = arr[r];

		int i = l;
		
		for(int j = l; j < r; j++){
			if(arr[j] <= pivot){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i++;
			}
		}
		int tmp = arr[i];
		arr[i] = arr[r];
		arr[r] = tmp;

		return i;
	}
	public static void quicksort(int[] arr, int l, int r){
		if(l >= r)
			return;
		int pivot = partition(arr, l, r);
		
		quicksort(arr, l, pivot -1);
		quicksort(arr, pivot + 1, r);
	}

	public static void main (String [] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] arr = new int[1024];
			
		for(int i = 0; i < n; i++)
			arr[i] = in.nextInt();
		arr[n] = -2100000000;

		quicksort(arr, 0, n - 1);

		for(int i = 0; i < n; i++)
			System.out.print(arr[i]+" ");
	}
}
