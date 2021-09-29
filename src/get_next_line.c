#include "../include/get_next_line.h"

int make_line(int fd, char **save, char **line)
{
	int i = 0;
	char *tmp;

	while(save[fd][i] != '\0' && save[fd][i] != '\n')
		i++;
	if(save[fd][i] == '\0')
	{
		*line = ft_strdup(save[fd]);
		free(save[fd]);
		return 0;
	}
	
	*line = ft_substr(save[fd],0,i);
	tmp =  ft_strdup(&save[fd][i+1]);
	free(save[fd]);
	save[fd] = tmp;
	return 1;
}

int check_ret(int fd, char **save, int ret, char **line)
{
	if(ret < 0)
		return -1;
	if(ret == 0 && save[fd] == NULL)
	{
		*line = ft_strdup("");
		return 0;
	}
	return make_line(fd,save,line);
}

int get_next_line(int fd, char **line)
{
	int ret;
	int flag = 0;
	char *buff;
	char static *save[8];
	char *tmp;

	if(!(buff = (char*)malloc(sizeof(char)*1001)))
		return -1;
	if(save[fd] && ft_strchr(save[fd],'\n') != NULL)
	{
		flag = 1;
		ret = 1;
	}
	
	while(flag != 1 && (ret = read(fd,buff,1000)) > 0)
	{
		buff[ret] = '\0';
		if(!(save[fd]))
		{
			save[fd] = ft_strdup(buff);
		}
		else
		{
			tmp = ft_strjoin(save[fd],buff);
			free(save[fd]);
			save[fd] = tmp;
		}

		if(ft_strchr(save[fd],'\n') != NULL)
			break;
	}
	free(buff);
	return check_ret(fd,save,ret,line);
}
