#View Model

##Self Function:
### exec_open_file_command(std::string filepath);
   > turn the filepath from view part into the style which model part needs;
### delete_part_command(/*struct*/)
   > use a struct define in the view, which give the viewmodel part filepath, time1, time2;
   >
   > turn them into model style;
   >
   > use modle part function to get the part which add the 0-time1 + time2-end product;
### add_parts_command(string view_filepath1, string view_filepath2)
   > exec filepath1 and filepath2
   > 
   > use funtion in model to get model1, model2 and model1 + model2;
### save_command (string view_newfilepath, string view_oldfilepath)
    > exec the filepathes
    >
    > use model1 to open file in modelview_path1, which is exec by view_filepath1
    > and store the message
    >
    > return the model1
### reverse_command (string filepath)
    > exec the filepath
    > use model to reverse the file in model_filepath

## External function
model::
    '''c
    getpart(time1, time2, filepath);        //get the model in filepath between time1 and time2 
    addpart(model1, model2);		    //merge two model into one, model1 in before
    getfile(filepath);			    //get the model by filepath 
    filereverse(filepath);		    //get the model by filepath and  get it reversed
    '''

