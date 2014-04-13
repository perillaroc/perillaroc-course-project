corr <- function(directory, threshold = 0) {
  ## 'directory' is a character vector of length 1 indicating
  ## the location of the CSV files
  
  ## 'threshold' is a numeric vector of length 1 indicating the
  ## number of completely observed observations (on all
  ## variables) required to compute the correlation between
  ## nitrate and sulfate; the default is 0
  
  ## Return a numeric vector of correlations
  
  result = numeric(length = 0)
  
  for(i in 1:332)
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
    
    current_set<-current_file[!is.na(current_file["sulfate"]),]
    current_set<-current_set[!is.na(current_set["nitrate"]),]
    if(nrow(current_set)>threshold){
      result<-c(result,cor(current_set["sulfate"], current_set["nitrate"]))
    }
     
  }
  result
}