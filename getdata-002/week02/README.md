#Week 02 笔记

## Reading from MySQL

### Windows下安装RMySQL包

参考网页

[http://biostat.mc.vanderbilt.edu/wiki/Main/RMySQL](http://biostat.mc.vanderbilt.edu/wiki/Main/RMySQL "RMySQL")

[http://www.ahschulz.de/2013/07/23/installing-rmysql-under-windows/](http://www.ahschulz.de/2013/07/23/installing-rmysql-under-windows/)

#### Rtools

下载安装包直接默认安装即可。

#### MySQL

安装MySQL这个不再赘述。

添加MySQL路径信息到R的环境变量文件`Renviron.site`。没有该文件则需要在R根目录的`etc`目录下创建，并加入下面一行，设置MYSQL的目录。

	MYSQL_HOME=D:/Program Files/MySQL/MySQL Server 5.6

#### RMySQL

重新启动R，安装RMySQL包即可。

	install.packages('RMySQL',type='source')

第一次安装时失败，提示没有找到`libmysql.dll`文件：

	gcc.exe: error: D:/Program Files/MySQL/MySQL Server 5.6/bin/libmySQL.dll: No such file or directory
	ERROR: compilation failed for package 'RMySQL'

该动态链接库文件在`mysql/lib`目录下，不知道要在`bin`目录下寻找，最简单的解决办法就是直接将`libmySQL.dll`文件直接拷贝到bin目录下。

### 数据集 UCSC Genome Bioinformatics

说明

[https://genome.ucsc.edu/goldenPath/help/mysql.html](https://genome.ucsc.edu/goldenPath/help/mysql.html)

连接数据库

	> ucscDb<-dbConnect(MySQL(), user="genome",host="genome-mysql.cse.ucsc.edu")
	> result<-dbGetQuery(ucscDb, "show databases");
	> dbDisconnect(ucscDb)

连接特定数据库
	
	 > hg19<-dbConnect(MySQL(), db="hg19", user="genome",host="genome-mysql.cse.ucsc.edu")

获取数据表

	> allTables<-dbListTables(hg19)
	> length(allTables)

列，数据的维度

	> dbListFields(hg19,"affyU133Plus2")

行，执行sql语句
	
	> dbGetQuery(hg19, "select count(*) from affyU133Plus2")

获取表数据
	
	> affyData <- dbReadTable(hg19, "affyU133Plus2")

上述语句执行速度慢，因为整个表的数据量很大。

子集

	> query<- dbSendQuery(hg19, "select * from affyU133Plus2 where misMatches between 1 and 3")
	> affMis <- fetch(query)
	
	> affyMisSmal <- fetch(query,n=10)

关闭查询

	> dbClearResult(query)

关闭连接
	
	> dbDisconnect(hg19)


## Reading from HDF5

### HDF5简介

groups

* group header
* group symbol table

datasets

* header
* data array

### 创建HDF5文件


写数据

读数据

向特定index写入数据


## Reading data from the web

## Reading data from APIs

## Reading from other sources


