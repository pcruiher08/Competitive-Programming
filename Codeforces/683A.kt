import java.util.Scanner
 
fun main(args: Array<String>) {
    val reader = Scanner(System.`in`)
    var a:Int = reader.nextInt()
    var x:Int = reader.nextInt()
    var y:Int = reader.nextInt()
    if (x < 0 || x > a || y < 0 || y > a)
      println(2)
    else if (x == 0 || x == a || y == 0 || y == a)
      println(1)
    else
      println(0)
 
 
}