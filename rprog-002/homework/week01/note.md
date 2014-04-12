#笔记

##1:

R的矩阵运算
	
元素运算

相同长度

不同长度：自动重复补全，如果长度无法整除，则给出警告。

##2: Sequences of Numbers

###seq
seq(0, 10, by=0.5)

seq(5,10, length=30)

创建相同长度的序列

* 1:length(my_seq)
* seq(along = my_seq)
* seq_along(my_seq)

###rep
rep(0,times=40)

rep(c(0,1,2),each=10)

##3： Vectors
类型

* atomic vectors
* lists

###logical vector

logical operators

A|B A&B !A

###character vector

连接：paste(my_char, collapse =" ")

paste("Hello", "world!", sep=" ")

paste(1:3, c("X","Y","Z"), sep="")

[1] "1X" "2Y" "3Z"

##4: Missing Values

NA: not available，just a placeholder

标准分布： rnorm(1000)

随机取样： sample(c(y, z), 100)

NaN

INF

##5: Subsetting Vectors

x[1:10]

x[!is.na(x)&x>0]

one-based indexing 与matlab类似

x[c(3,5,7)]

x[0] numeric(0)

x[3000] NA

排除某些点，使用-号： x[c(-2,-10)] 或者更简便的形式 x[-c(2,10)]

###Name

有名字的元素，c(foo=11,bar=2, norf=NA)

names()

指定名称

	names(vect2)<-c("foo","bar","norf")

是否一样

	identical(vect1, vect2)

使用带名字的vector

	vect["bar"]

##6: Matrices and Data Frames

Matrix只能存放相同类型的数据，Data Frame可以存放不同类型的数据。

设置维度
	
	dim(myVector)<-c(4,5)

查看属性：attributes(myVector)

Matrix：有维度属性(dim)的矢量vector

matrix函数：

	matrix(data=1:20, nrow=4, ncol=5)

combine columns: cbind(patients, myMatrix)

###Data Frames

创建
	
	data.frame(patients,myMatrix)

添加列名

	colnames(myData)<-cnames




