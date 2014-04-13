pollutantmean <- function(directory, pollutant, id = 1:332) {
  ## 'directory' is a character vector of length 1 indicating
  ## the location of the CSV files
  
  ## 'pollutant' is a character vector of length 1 indicating
  ## the name of the pollutant for which we will calculate the
  ## mean; either "sulfate" or "nitrate".
  
  ## 'id' is an integer vector indicating the monitor ID numbers
  ## to be used
  
  ## Return the mean of the pollutant across all monitors list
  ## in the 'id' vector (ignoring NA values)
  
  data_set <- c()
  for(i in id)
  {
    name<-i
    if(i<10){
      name<-paste("00",i,sep="")
    }
    else if(i<100){
      name<-paste("0",i,sep="")
    }
    file_name<-paste(directory,"/",name,".csv",sep="")
    current_file<-read.csv(file_name)
    current_set<-current_file[pollutant]
    data_set<-c(data_set,current_set[!is.na(current_set)])
  }
  mean(data_set)
}