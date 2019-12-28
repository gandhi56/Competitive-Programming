(defun fn(n)
  (loop for x from 1 to n
    do (write-line "Hello World")      
  )
)

(fn (read))

