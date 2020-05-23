import java.util.Scanner

fun main(){
  val inp = Scanner(System.`in`)
  val t = inp.nextInt()
  for (tt in 0..t-1){
    val n = inp.nextInt()
    if (n <= 3){
      println(-1)
      continue
    }

    val a = mutableListOf<Int>()
    val s = mutableSetOf<Int>()
    for (start in 1..n){
      a.clear()
      s.clear()
      a.add(start)
      s.add(start)
      while (a.size < n){
        var ok = false
        for (delta in arrayOf(-4,-3,-2,2,3,4)){
          val x = a.last() + delta
          if (x !in s && x >= 1 && x <= n){
            a.add(x)
            s.add(x)
            ok = true
            break
          }
        }
        if (!ok) break
      }
      if (a.size == n)  break
    }

    for (x in a){
      print("$x ")
    }
    println()
  }
}