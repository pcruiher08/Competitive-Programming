import java.util.Scanner;

	public class suma {
		public static void main(String [] args) {
			
			Scanner input = new Scanner(System.in);
			int n = 0;
                        int suma = 0;

			n = input.nextInt();

			if (n > 0) {
				for (int i = 1; i <= n; i++) {
					suma = suma + i;
				}
			}
			else if (n <= 1) {
				for (int e = 1; e >= n; e--) {
					suma = suma + e;
				}
			}

			System.out.println(suma);

		}
	}