import java.util.Scanner

fun main(){
  val inp = Scanner(System.`in`)
  var t = inp.nextInt()
  while (t > 0){
    var a = inp.nextInt()
    var b = inp.nextInt()
    var c = inp.nextInt()
    var d = inp.nextInt()
    if ((a == c && b+d==a) || (a == d && b+c == a) || 
        (b == c && a+d==b) || (b == d && a+c == b)){
      println("YES")
    }
    else{
      println("NO")
    }
    t--
  }
}