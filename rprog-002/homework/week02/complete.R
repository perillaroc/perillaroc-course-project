complete <- function(directory, id = 1:332) {
  ## 'directory' is a character vector of length 1 indicating
  ## the location of the CSV files
  
  ## 'id' is an integer vector indicating the monitor ID numbers
  ## to be used
  
  ## Return a data frame of the form:
  ## id nobs
  ## 1  117
  ## 2  1041
  ## ...
  ## where 'id' is the monitor ID number and 'nobs' is the
  ## number of complete cases
  
  id_count<-length(id)
  counts<-seq_along(id)
  for(j in 1:id_count)
  {
    i = id[j]
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
    counts[j]<-nrow(current_set[!is.na(current_set['nitrate']),])
  }
  data.frame(id=id, nobs=counts)

}