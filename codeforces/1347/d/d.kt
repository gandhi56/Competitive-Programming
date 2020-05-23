import java.util.Scanner

fun main() {
    val inp = Scanner(System.`in`)
    val t = inp.nextInt()
    for (tt in 1..t){
        var n = inp.nextInt()
        var tot = 0
        var ar = mutableListOf<Int>()
        for (i in 1..n){
            var x = inp.nextInt()
            ar.add(x)
            tot += x
        }

        var m = 0
        var a = 0
        var b = 0
        var tota = 0
        var totb = 0
        var i = -1
        var j = n
        var p1 = true
        while (tota + totb < tot){
            if (p1){
                a = 0
                i++
                while (i < j){
                    a += ar[i]
                    if (a > b)  break
                    i++
                }
                tota += a
            }
            else{
                b = 0
                j--
                while (i < j){
                    b += ar[j]
                    if (b > a)  break
                    j--
                }
                totb += b
            }
            p1 = !p1
            m++
        }

        println("$m $tota $totb")
    }
}